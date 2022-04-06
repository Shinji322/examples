#!/bin/sh

var="apple orange"

echo ${var#*} # deletes nothing. Single pound means glob match conservatively
echo ${var##*} # deletes everything. Double pound means glob match greedily


echo ${var#*p}  # => "ple orange"
echo ${var##*p} # => "le orange"

echo ${var%p*}  # => "app"
echo ${var%%p*} # => "ap"

echo ${var%% *} # => "apple"
echo ${var##* } # => "orange"
