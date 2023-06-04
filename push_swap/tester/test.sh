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
for i in {1..1000}
do
	args=`seq $n_option | sort -R | xargs`
	res=`./push_swap $args | wc -l`
	check=`./push_swap $args | ./tester/checker_Mac $args`
	if [ $check == "OK" ]; then
		echo -e "\033[32mTEST $i OK (op cnt: $res)\033[0m"
	else
		echo -e "\033[31mTEST $i KO\033[0m"
	fi
	sum=$((sum+res))
	if [ $((res + 0)) -gt $max ]; then
		max=$res
	fi
	if [ $min -gt $((res + 0)) ]; then
		min=$res
	fi
done
avg=$((sum/1000))

# Print Result
echo "Max: $max, Min: $min"
echo "Average: $avg"
