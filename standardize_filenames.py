#!/usr/bin/env python3
import os
import json
import shutil
from typing import Dict, List

# Load the problem list to get the standardized names
with open('problems/problem_list.json', 'r') as f:
    problem_data = json.load(f)

# Create a mapping from order number to standardized filename
# Map by category and order number
filename_map: Dict[str, Dict[str, str]] = {}

# Process each category in the problem list
for category_key, problems in problem_data.items():
    if not problems:  # Skip empty categories
        continue
    # Create a mapping for this category
    category_map: Dict[str, str] = {}
    category_map = {}
    for problem in problems:
        # Extract the order number and create the standardized filename without extension
        order = problem['order']
        problem_id = problem['id']
        title = problem['title']
        standardized_name = f"{order}_{problem_id}_{title.replace(' ', '_')}"
        category_map[order] = standardized_name
    
    # Store the mapping for this category
    filename_map[category_key] = category_map

# Process each solution directory
solution_dir = 'solutions'
categories = [d for d in os.listdir(solution_dir) if os.path.isdir(os.path.join(solution_dir, d))]

errors: List[str] = []
renamed_files: List[str] = []

for category in categories:
    category_path = os.path.join(solution_dir, category)
    files = [f for f in os.listdir(category_path) if os.path.isfile(os.path.join(category_path, f))]
    
    # Skip if the category is not in our mapping
    if category not in filename_map:
        errors.append(f"Category {category} not found in problem list")
        continue
    
    category_map = filename_map[category]
    
    for filename in files:
        old_path = os.path.join(category_path, filename)
        
        # Determine the order number from the filename
        order = None
        if '_' in filename:
            # Handle case like "01_1068.py"
            order = filename.split('_')[0]
        else:
            # Handle case like "01.cpp"
            order = filename.split('.')[0]
            
        # If the order is numeric but not zero-padded, pad it
        if order.isdigit() and len(order) == 1:
            order = f"0{order}"
            
        # If the order is not in the expected format, skip
        if not order or order not in category_map:
            errors.append(f"Could not determine order for {filename} in {category}")
            continue
            
        # Get file extension
        _, extension = os.path.splitext(filename)
        
        # Construct the new filename
        new_filename = f"{category_map[order]}{extension}"
        new_path = os.path.join(category_path, new_filename)
        
        # Rename the file
        try:
            shutil.move(old_path, new_path)
            renamed_files.append(f"{category}/{filename} → {category}/{new_filename}")
        except Exception as e:
            errors.append(f"Failed to rename {filename}: {e}")

# Print summary
print(f"Standardized {len(renamed_files)} solution files.")
if renamed_files:
    print("\nRenamed files:")
    for renamed in renamed_files:
        print(f"  {renamed}")

if errors:
    print("\nErrors:")
    for error in errors:
        print(f"  {error}")