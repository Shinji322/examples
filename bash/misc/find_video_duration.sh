#!/bin/bash
# Made by Fujiwara No Mokou

duration=$(echo "$(mediainfo $1)" | grep "Duration" | uniq)
time=$(echo "${duration#*:}")

echo $time
