#!/bin/bash
if [ $1 -lt 0 ]
then
    echo "The number is negative"
elif [ $1 -gt 0 ]
then
    echo "The number is positive"
else
    echo "The number is zero"
fi
