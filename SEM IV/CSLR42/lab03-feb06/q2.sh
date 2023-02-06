#!/bin/bash
sum=$(($(($1 * $(($1 + 1))))/2))
echo "The sum of the first $1 natural number is $sum"
