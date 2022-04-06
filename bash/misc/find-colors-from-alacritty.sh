#!/bin/sh

# search for hexadecimal colors (0x) in alacritty.yml
# get rid of all the comments (#.*) and whitespaces (\s*)
# there's a random color variable so delete that
# also delete blank lines (^$)
colors=$(grep -R '0x' 'alacritty/alacritty.yml' | sed 's/\s*#.*//g;/color.*/d;/^$/d')

echo "$colors"
