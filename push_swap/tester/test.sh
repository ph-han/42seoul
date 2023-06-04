#!/bin/bash
##########################
#						 #
# push_swap_tester.sh	 #
# created: 2023/06/03	 #	
#						 #
##########################
#

# Option
n_option=100
while getopts n: opt
do
    case ${opt} in
        n) n_option="$OPTARG" ;;
    esac
done

# Test
sum=0
max=-1
min=2147483647
for i in {1..300}
do
	args=`seq $n_option | sort -R | xargs`
	res=`./push_swap $args | wc -l`
	echo "test $i case (op cnt: $res)"
	sum=$((sum+res))
	if [ $((res + 0)) -gt $max ]; then
		max=$res
	fi
	if [ $min -gt $((res + 0)) ]; then
		min=$res
	fi
done
avg=$((sum/300))

# Print Result
echo "Max: $max, Min: $min"
echo "Total(1~300): $sum"
echo "Average: $avg"
