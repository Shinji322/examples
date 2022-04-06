#!/bin/bash
# This script updates mimeappas.list and edits it so all text/.* files are opened with text.desktop
# Status TODO

filetypes=$(cat mimeapps.list)
regex="text/.*="

for f in $filetypes
do 
    if [[ $f =~ $regex ]]
    then
        name="${BASH_REMATCH[0]}"
        echo "${name}text.desktop"
    fi
done
