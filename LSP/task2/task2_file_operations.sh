#!/bin/bash

# Create directory structure and navigate into it
mkdir -p /tmp/myfiles
cd /tmp/myfiles || exit 1

# Create three text files with sample content
echo "This is file one." > file1.txt
echo "This is file two." > file2.txt
echo "This is file three." > file3.txt

# List all files in the directory
echo "Files in /tmp/myfiles:"
ls -l

# Change permissions of file1.txt to read-only for group
chmod g=r file1.txt

# Display updated permissions of file1.txt
echo "Updated permissions for file1.txt:"
ls -l file1.txt
