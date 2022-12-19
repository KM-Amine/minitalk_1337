#!/bin/bash
if [ $1 -eq 1 ]
then
	killall server
	echo server killed
	exit
fi
SERVERID=$(pgrep server | tr '\n' ' ' | awk '{print $2}')
echo  $SERVERID;

len=$(echo $SERVERID | wc -c)
if [ $len -eq 1 ]
then
	./server &
fi
PROCCESS=$(top -l 1 | grep client | wc -l | tr -d ' ')
for i in {1..100000}
do
	# if [ $PROCCESS -eq 0 ]
	# then
		./client $SERVERID  📗
	# 	kill -1 $(top -l 1 | grep client | awk '{print $1}')
	# fi
done
