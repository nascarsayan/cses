import os
import requests
from bs4 import BeautifulSoup, Tag
import time
import logging
import json
import re
import html2text
from typing import Dict, List, Optional

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

# Base URLs and paths
BASE_URL = "https://cses.fi"
PROBLEM_LIST_URL = f"{BASE_URL}/problemset/list/"
PROBLEMS_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)))
PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONFIG_PATH = os.path.join(PROJECT_ROOT, "config.yaml")

class CSESProblemScraper:
    def __init__(self) -> None:
        self.session = requests.Session()
        self.headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
        }
    
    def get_problem_list(self) -> Optional[List[Dict[str, str]]]:
        """Scrape the problem list from the CSES website."""
        logger.info("Fetching problem list from CSES...")
        response = self.session.get(PROBLEM_LIST_URL, headers=self.headers)
        if response.status_code != 200:
            logger.error(f"Failed to fetch problem list. Status code: {response.status_code}")
            return None
        
        soup = BeautifulSoup(response.text, 'html.parser')
        problems: List[Dict[str, str]] = []
        
        # Find all problem categories
        categories = soup.find_all('h2')
        
        for category in categories:
            category_name = category.text.strip()
            if not category_name or category_name == "CSES Problem Set":
                continue
                
            # Find the next ul element
            problem_list_elem = category.find_next('ul')
            if not problem_list_elem:
                continue
                
            # Find all li elements in the ul
            problem_items: List[Tag] = problem_list_elem.find_all('li') # type: ignore
            
            for item in problem_items:
                # Find the link inside the li
                link_elem = item.find('a')
                if not link_elem or not hasattr(link_elem, 'href'):
                    continue
                
                # Filter out links that don't match the problem pattern
                # First ensure link_elem is a Tag to access href
                if isinstance(link_elem, Tag) and 'href' in link_elem.attrs:
                    href = link_elem.attrs['href']
                    if not isinstance(href, str) or not href.startswith('/problemset/task/'):
                        continue
                        
                    problem_url = f"{BASE_URL}{href}"
                    problem_id = problem_url.split('/')[-1]
                    
                    # Get the text from the link
                    problem_title = link_elem.text.strip()
                    
                    problems.append({
                        'id': problem_id,
                        'title': problem_title,
                        'category': category_name,
                        'url': problem_url
                    })
        
        logger.info(f"Found {len(problems)} problems across {len(categories) - 1} categories")
        return problems
    
    def get_problem_content(self, problem_url: str) -> Optional[str]:
        """Download the problem statement HTML."""
        logger.info(f"Fetching problem from {problem_url}")
        response = self.session.get(problem_url, headers=self.headers)
        if response.status_code != 200:
            logger.error(f"Failed to fetch problem. Status code: {response.status_code}")
            return None
        
        soup = BeautifulSoup(response.text, 'html.parser')
        problem_content = soup.find('div', class_='content')
        
        if not problem_content:
            logger.error("Couldn't find problem content")
            return None
            
        return str(problem_content)
    
    def convert_html_to_markdown(self, html_content: str, problem_title: str) -> str:
        """Convert HTML problem statement to Markdown using html2text."""
        try:
            # Custom processing to handle LaTeX syntax
            soup = BeautifulSoup(html_content, 'html.parser')
            
            # Type-safe iteration through math elements
            for math in soup.find_all('span', class_='math'):
                if isinstance(math, Tag):
                    # Get the text content
                    math_text = math.string if math.string else ""
                    # Update the string content
                    math.string = f"${math_text}$"
                    
            for math in soup.find_all('div', class_='math'):
                if isinstance(math, Tag):
                    # Get the text content
                    math_text = math.string if math.string else ""
                    # Update the string content
                    math.string = f"$$\n{math_text}\n$$"
            
            processed_html = str(soup)
            markdown_content = html2text.html2text(processed_html)
            return markdown_content
        except Exception as e:
            logger.error(f"Error in HTML to Markdown conversion: {e}")
            # Fallback to a simple HTML -> MD conversion if conversion fails
            return f"# {problem_title}\n\n[Original problem]({problem_title})\n\n(Error converting to Markdown - please check the original problem)"
    
    def save_markdown(self, problem: Dict[str, str], markdown_content: str) -> str:
        """Save the markdown content to file."""
        # Create directory structure if it doesn't exist
        category_dir = os.path.join(PROBLEMS_DIR, self._sanitize_filename(problem['category']))
        os.makedirs(category_dir, exist_ok=True)
        
        # Create filename from problem title
        filename = f"{problem['id']}_{self._sanitize_filename(problem['title'])}.md"
        filepath = os.path.join(category_dir, filename)
        
        with open(filepath, 'w', encoding='utf-8') as f:
            # Add frontmatter with metadata
            f.write("---\n")
            f.write(f"title: \"{problem['title']}\"\n")
            f.write(f"category: \"{problem['category']}\"\n")
            f.write(f"url: \"{problem['url']}\"\n")
            f.write(f"id: {problem['id']}\n")
            f.write("---\n\n")
            f.write(markdown_content)
        
        logger.info(f"Saved markdown for '{problem['title']}' at {filepath}")
        return filepath
    
    def _sanitize_filename(self, name: str) -> str:
        """Convert string to a valid filename."""
        return re.sub(r'[^\w\s-]', '', name).strip().replace(' ', '_')
    
    def check_if_exists(self, problem: Dict[str, str]) -> bool:
        """Check if markdown file for problem already exists."""
        category_dir = os.path.join(PROBLEMS_DIR, self._sanitize_filename(problem['category']))
        if not os.path.exists(category_dir):
            return False
            
        # Check for any file starting with the problem ID
        filename_prefix = f"{problem['id']}_"
        for filename in os.listdir(category_dir):
            if filename.startswith(filename_prefix) and filename.endswith('.md'):
                return True
        
        return False
    
    def process_all_problems(self) -> None:
        """Process all problems from CSES."""
        problems = self.get_problem_list()
        if not problems:
            logger.error("Failed to get problem list")
            return
        
        # Save problem list as JSON for reference
        with open(os.path.join(PROBLEMS_DIR, 'problem_list.json'), 'w', encoding='utf-8') as f:
            json.dump(problems, f, indent=2)
        
        logger.info("Processing problems...")
        for i, problem in enumerate(problems):
            try:
                if self.check_if_exists(problem):
                    logger.info(f"[{i+1}/{len(problems)}] Problem '{problem['title']}' already exists, skipping")
                    continue
                
                logger.info(f"[{i+1}/{len(problems)}] Processing problem '{problem['title']}'")
                html_content = self.get_problem_content(problem['url'])
                if not html_content:
                    logger.warning(f"Couldn't get content for {problem['title']}, skipping")
                    continue
                
                markdown_content = self.convert_html_to_markdown(html_content, problem['title'])
                self.save_markdown(problem, markdown_content)
                
                # Be nice to the server
                time.sleep(2)
            except Exception as e:
                logger.error(f"Error processing problem '{problem['title']}': {e}")
                
        logger.info("Finished processing all problems")

if __name__ == "__main__":
    scraper = CSESProblemScraper()
    scraper.process_all_problems()
