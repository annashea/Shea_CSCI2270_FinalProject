#!/bin/bash
#Anna Shea
file="$1"
if [ -f "$file" ]
then
	#sort -k 3,3 -k 2,2 -k 1,1 $1 
	while i in $1
	do
		t+='$i' 
	done
	#echo "int(t/3), "["$1"]", $3",",$2"
	echo "$t"
	t=0
else
	echo -e "Usage: grades.sh filename \nUsage: grades-awk.sh filename"
fi
