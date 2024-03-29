#!/bin/bash

# Loop through each .c file in the current directory
for file in *.c; do
    # Check style
    perl betty-style.pl "$file"
    
    # Check documentation
    perl betty-doc.pl "$file"
    
    # Fix style and documentation
    betty-style.pl -f "$file"
    betty-doc.pl -f "$file"
done

