#!/bin/bash
echo enter a number :
read number
	if [ $number -lt 0 ]
	then
		echo positive
	elif [ $number -gt 0 ]
	then
		echo negative

	else
		echo zero
fi
