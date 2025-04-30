#!/bin/bash

# Variables
file="sample.txt"
word="error"

# Check if the file exists
if [[ -f "$file" ]]; then
    echo "Listing all occurrences of \"$word\" in $file (sorted alphabetically):"
    grep -i "$word" "$file" | sort
else
    echo "File $file not found."
fi

