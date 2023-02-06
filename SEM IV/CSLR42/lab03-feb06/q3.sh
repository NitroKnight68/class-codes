#!/bin/bash
birth=$1
n=0 
sum=0
while [ $n -lt 8 ]
do
    sum=$(($sum + ${birth:$n:1}))
    n=$(($n + 1))
done
echo  "Sum of all the digits in DDMMYY is $sum"
