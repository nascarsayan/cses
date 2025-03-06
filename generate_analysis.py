#!/usr/bin/env python3
"""
Script to generate analysis files for CSES problems using LLM.
It takes problem statements and solution files, then generates analysis markdown files.
"""

import os
import json
import yaml
import re
import logging
import argparse
from pathlib import Path
import requests
from typing import Dict, List, Optional, Any, Tuple

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger("cses-analysis")

class AnalysisGenerator:
    def __init__(self, config_path: str):
        """Initialize with config file path."""
        self.base_dir = Path(os.path.dirname(os.path.abspath(__file__)))
        self.problems_dir = self.base_dir / 'problems'
        self.solutions_dir = self.base_dir / 'solutions'
        self.analysis_dir = self.base_dir / 'analysis'
        
        self.config = self._load_config(config_path)
        self.problems = self._load_problems()
    
    def _load_config(self, config_path: str) -> Dict:
        """Load config from YAML file."""
        try:
            with open(config_path, 'r') as file:
                return yaml.safe_load(file)
        except Exception as e:
            logger.error(f"Failed to load config from {config_path}: {e}")
            raise

    def _load_problems(self) -> Dict:
        """Load problem list from problems/problem_list.json."""
        try:
            with open(self.problems_dir / 'problem_list.json', 'r') as file:
                return json.load(file)
        except Exception as e:
            logger.error(f"Failed to load problems: {e}")
            raise

    def get_llm_analysis(self, problem_path: Path, solution_path: Path) -> str:
        """Generate analysis using LLM API call."""
        # Check if files exist
        if not problem_path.exists():
            raise FileNotFoundError(f"Problem file not found: {problem_path}")
        
        # If solution doesn't exist, mention it in the analysis
        solution_content = "Solution file not available."
        if solution_path.exists():
            with open(solution_path, 'r') as file:
                solution_content = file.read()
        
        with open(problem_path, 'r') as file:
            problem_content = file.read()

        # Get model configuration
        model_config = self.config.get('models', [])[0]
        if not model_config:
            raise ValueError("No model configuration found in config")
        
        endpoint = model_config.get('endpoint')
        api_key = model_config.get('key')
        deployment = model_config.get('chatDeployment')
        api_version = model_config.get('version')
        
        # Prepare the prompt for the LLM
        prompt = f"""
Analyze this competitive programming problem and its solution:

# Problem Statement:
{problem_content}

# Solution:
{solution_content}

Write a comprehensive analysis in markdown format with the following sections:
* TL;DR - A few-sentence summary of the solution approach
* Problem Overview - Brief description of the problem
* Solution Approach - Detailed explanation of how the solution works
* Key Learning Points - Important concepts to understand from this problem
* Common Pitfalls - Mistakes to avoid
* Complexity - Time and space complexity analysis
* Alternative Approaches - Other ways to solve the problem
* Extended Learning - Related concepts
* Tips for Similar Problems - How to recognize and solve similar problems

Generate markdown formatted output only.
Use Github-style markdown with single line ($) or multiline ($$) for mathematical expressions.
Start with Heading 2 TL;DR, don't generate title or links (will add to output later).
Don't embed the full implementation in the analysis - just explain the key parts.
"""

        # Make API call to Azure OpenAI
        headers = {
            "Content-Type": "application/json",
            "api-key": api_key,
        }
        
        body = {
            "messages": [
                {"role": "system", "content": "You are an expert competitive programmer tasked with analyzing problems and their solutions."},
                {"role": "user", "content": prompt}
            ],
            "model": deployment,
            "max_tokens": 3000,
            "temperature": 0.3,
        }
        
        try:
            response = requests.post(
                f"{endpoint}/openai/deployments/{deployment}/chat/completions?api-version={api_version}",
                headers=headers,
                json=body
            )
            
            response.raise_for_status()
            result = response.json()
            analysis = result['choices'][0]['message']['content']

            # Remove leading ```markdown and trailing ```
            analysis = re.sub(r'^```markdown\n', '', analysis)
            analysis = re.sub(r'```\n$', '', analysis)
            return analysis
            
        except requests.exceptions.RequestException as e:
            logger.error(f"API call failed: {e}")
            raise

    def create_analysis_file(self, category_dir: str, problem_info: Dict) -> Optional[Path]:
        """Create an analysis markdown file for a specific problem."""
        problem_id = problem_info['id']
        order = problem_info['order']
        title = problem_info['title']
        ordered_category = problem_info['ordered_category']
        
        # File paths
        file_prefix = f"{order}_{problem_id}_{title.replace(' ', '_')}"
        problem_path = self.problems_dir / ordered_category / f"{order}_{problem_id}_{title.replace(' ', '_')}.md"
        solution_path = self.solutions_dir / ordered_category / f"{order}_{problem_id}_{title.replace(' ', '_')}.cpp"
        analysis_path = self.analysis_dir / ordered_category / f"{order}_{problem_id}_{title.replace(' ', '_')}.md"
        
        # Check if analysis file already exists
        if analysis_path.exists():
            logger.info(f"Analysis file already exists: {analysis_path}")
            return None

        # Create directory if it doesn't exist
        os.makedirs(analysis_path.parent, exist_ok=True)
        
        try:
            # Generate analysis using LLM
            analysis_content = self.get_llm_analysis(problem_path, solution_path)
            
            # Extract title from analysis or use problem title
            title_match = re.search(r'^# (.*?)$', analysis_content, re.MULTILINE)
            if title_match:
                # remove title from analysis content
                analysis_content = analysis_content.replace(title_match.group(0), '')

            # Add links to problem and solution
            analysis_content = f"# {title}\n\n[Problem Link]({problem_info['url']}) | [Solution Link](../../solutions/{ordered_category}/{order}_{problem_id}_{title.replace(' ', '_')}.cpp)\n\n" + analysis_content
            
            # Save analysis to file
            with open(analysis_path, 'w') as file:
                file.write(analysis_content)
            
            logger.info(f"Created analysis file: {analysis_path}")
            return analysis_path
        
        except Exception as e:
            logger.error(f"Failed to create analysis for {problem_path.name}: {e}")
            return None

    def generate_analyses(self, category_filter: Optional[str] = None, limit: Optional[int] = None) -> List[Path]:
        """Generate analysis files for all problems or a specific category."""
        generated_files = []
        count = 0

        # Process each category in the problems list
        for category, problems in self.problems.items():
            # Skip if not matching filter
            if category_filter and category_filter != category:
                continue
                
            logger.info(f"Processing category: {category}")
            
            for problem in problems:
                # Skip if we've reached the limit
                if limit is not None and count >= limit:
                    break
                    
                result = self.create_analysis_file(category, problem)
                if result:
                    generated_files.append(result)
                    count += 1
                    
                    # Break if we've reached the limit
                    if limit is not None and count >= limit:
                        break
        
        return generated_files

def main():
    parser = argparse.ArgumentParser(description='Generate analysis files for CSES problems using LLM')
    parser.add_argument('--config', type=str, default='config.yaml', help='Path to config.yaml file')
    parser.add_argument('--category', type=str, help='Category to process (e.g., "01_Introductory_Problems")')
    parser.add_argument('--limit', type=int, help='Maximum number of analyses to generate')
    args = parser.parse_args()
    
    try:
        generator = AnalysisGenerator(args.config)
        generated_files = generator.generate_analyses(args.category, args.limit)
        
        if generated_files:
            logger.info(f"Successfully generated {len(generated_files)} analysis files")
        else:
            logger.info("No new analysis files generated")
            
    except Exception as e:
        logger.error(f"An error occurred: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())