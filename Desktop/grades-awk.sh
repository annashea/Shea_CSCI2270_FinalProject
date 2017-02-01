#!/bin/bash
#Anna Shea
file="$1"
if [ -f "$file" ]
then
	sort -k 3,3 -k 2,2 -k 1,1 $1 |awk '{for(i=4;i<=NF;i++) t+=$i; print int(t/3), "["$1"]", $3",",$2; t=0}'
else
	echo -e "Usage: grades.sh filename \nUsage: grades-awk.sh filename"
fi
