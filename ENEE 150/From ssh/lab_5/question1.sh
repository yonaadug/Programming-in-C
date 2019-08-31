#!/bin/bash
echo Enter a year: 
read X
if [ $((X%400)) -eq 0 ] || ([ $((X%4)) -eq 0 ] && [ $((X%100)) -ne 0 ]); then
	echo It is a leap year
else
	echo It is not a leap year
fi
