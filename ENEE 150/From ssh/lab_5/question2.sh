#!/bin/bash
echo Enter a number of test integers to be entered: 
read X
if [ $X -gt 0 ]; then
	echo Enter the test integers:  
	read Y
	min=$Y
	max=$Y


	while [ $X -ne 1 ]
	do
		read Y
		if [ $Y -gt $max ]; then
			max=$Y
		fi
		
		if [ $Y -lt $min ]; then
			min=$Y
		fi
		
		X=$((X-1))
	done
	
	echo min: ${min} max: ${max}
else
	echo Number must be positive
	
fi
