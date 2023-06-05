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
input_100=(700 900 1100 1300 1500)
input_500=(5500, 7000, 8500, 10000, 11500)
for i in {1..1000}
do
	args=`seq $n_option | sort -R | xargs`
	res=`./push_swap $args | wc -l`
	check=`./push_swap $args | ./tester/checker_Mac $args`
	if [ $check == "OK" ]; then
		if [ $n_option -eq 5 ]; then
			if [ $((res + 0)) -lt 12 ]; then
				echo -e "\033[1;32mTEST $i OK (Moves: $res)\033[0m"
			fi
		elif [ $n_option -eq 100 ]; then
			if [ $((res + 0)) -lt ${input_100[0]} ]; then
				echo -e "\033[1;32mTEST $i OK (Moves: $res) [5/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_100[1]} ]; then
				echo -e "\033[32mTEST $i OK (Moves: $res) [4/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_100[2]} ]; then
				echo -e "\033[1;33mTEST $i OK (Moves: $res) [3/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_100[3]} ]; then
				echo -e "\033[33mTEST $i OK (Moves: $res) [2/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_100[4]} ]; then
				echo -e "\033[31mTEST $i OK (Moves: $res) [1/5]\033[0m"
			else
				echo -e "\033[31mTEST $i KO (Moves: $res) [0/5]\033[0m"
			fi
		elif [ $n_option -eq 500 ]; then
			if [ $((res + 0)) -lt ${input_500[0]} ]; then
				echo -e "\033[1;32mTEST $i OK (Moves: $res) [5/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_500[1]} ]; then
				echo -e "\033[32mTEST $i OK (Moves: $res) [4/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_500[2]} ]; then
				echo -e "\033[1;33mTEST $i OK (Moves: $res) [3/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_500[3]} ]; then
				echo -e "\033[33mTEST $i OK (Moves: $res) [2/5]\033[0m"
			elif [ $((res + 0)) -lt ${input_500[4]} ]; then
				echo -e "\033[31mTEST $i OK (Moves: $res) [1/5]\033[0m"
			else
				echo -e "\033[31mTEST $i KO (Moves: $res) [0/5]\033[0m"
			fi
		else  
			echo -e "\033[31mTEST $i OK (Moves: $res)\033[0m"
		fi
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
