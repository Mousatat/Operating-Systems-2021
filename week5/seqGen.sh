#!/bin/bash
for i in $(seq 10)
do
	lockfile -r 0 out.lock || exit 1
	lst=$( tail -n 1 out.txt)	
	echo "$(($lst+1))">>out.txt
	rm -f out.lock
done
