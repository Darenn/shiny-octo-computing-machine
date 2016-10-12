#!/bin/bash
# Merge all files given by a file's list into another file,
# deleting #include directives for local libraries.

# Arguments :
# The file's list containing the list of files to merge
# (in the good order, one file name per line)
filesList="$2"

# The file where to merge
to="$1"

temp=$(mktemp) # Temporary file

cat "$temp"

# Get all "#include <*>" and copy them to top of $to file
grep -he "#include <.*>" -r include src | sort -u > "$to"

# Get all hpp and cpp and add them to $temp file
while IFS='' read -r line || [[ -n "$line" ]]; do
    cat "$line" >> "$temp"
done < "$filesList"

# Remove all "#include" directives from the $temp file and add it to $to file
sed '/^#include/d' "$temp" >> "$to"

# Remove temporary file
rm -rf "$temp"
