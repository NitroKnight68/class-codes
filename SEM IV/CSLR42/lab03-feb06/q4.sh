#!/bin/bash

for ((i = 1; i <= $#; i++ )); do
  	marks=${!i}
	if [ $marks -le 100 -a $marks -ge 90 ]
	then
	    echo "Student $i is allocated AA grade"
	elif [ $marks -lt 90 -a $marks -ge 80 ]
	then
	    echo "Student $i is allocated AB grade"
	elif [ $marks -lt 80 -a $marks -ge 70 ]
	then
	    echo "Student $i is allocated BB grade"
	elif [ $marks -lt 70 -a $marks -ge 60 ]
	then
	    echo "Student $i is allocated BC grade"
	elif [ $marks -lt 60 -a $marks -ge 50 ]
	then
	    echo "Student $i is allocated CC grade"
	elif [ $marks -lt 50 -a $marks -ge 40 ]
	then
	    echo "Student $i is allocated CD grade"
	elif [ $marks -lt 40 -a $marks -ge 30 ]
	then
	    echo "Student $i is allocated D grade"
	else
	    echo "Student $i is allocated F grade"
	fi
done

