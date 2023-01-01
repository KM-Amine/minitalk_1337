#!/bin/bash

SERVERID=$(top -l 1 | grep server_bonus | awk '{print $1}')
PROCCESS=$(top -l 1 | grep client_bonus | wc -l | tr -d ' ')
for i in {1..100000}
do
	if [ $PROCCESS -eq 0 ]
	then
		./client_bonus $SERVERID  "📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗📗"
	else
		kill -1 $(top -l 1 | grep client_bonus | awk '{print $1}')
	fi
done
#!/bin/bash
# if [ $1 -eq 1 ]
# then
# 	killall server
# 	echo server killed
# 	exit
# fi
# SERVERID=$(pgrep server_bonus | tr '\n' ' ' | awk '{print $2}')
# echo  $SERVERID;

# len=$(echo $SERVERID | wc -c)
# # if [ $len -eq 1 ]
# # then
# # 	./server_bonus &
# # fi
# PROCCESS=$(top -l 1 | grep client | wc -l | tr -d ' ')
# for i in {1..100000}
# do
# 	# if [ $PROCCESS -eq 0 ]
# 	# then
# 		./client_bonus $SERVERID  📗
# 	# 	kill -1 $(top -l 1 | grep client | awk '{print $1}')
# 	# fi
# done

# ddos
# long message 
# multiple clients