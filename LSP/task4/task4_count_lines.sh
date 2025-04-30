#!/bin/bash

# Function to count and print number of lines in a file
count_lines() {
    local file=$1
    if [[ -f "$file" ]]; then
        local lines
        lines=$(wc -l < "$file")
        echo "$file: $lines lines"
    else
        echo "$file: File not found"
    fi
}

# List of files
files=("file1.txt" "file2.txt" "file3.txt")

# Loop over the file list
for file in "${files[@]}"; do
    count_lines "$file"
done

