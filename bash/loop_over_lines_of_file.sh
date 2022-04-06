while IFS= read -r line
do 
    cp -rn -- "$line" .
done  < "$HOME/.local/share/lf/files"
