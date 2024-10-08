#include <stdio.h>

#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"

int	main ()
{	
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("--ex00--\n");
	printf("-1! = 0 --> %d\n", ft_iterative_factorial(-1));
	printf("0! = 1 --> %d\n", ft_iterative_factorial(0));
	printf("4! = 24 --> %d\n", ft_iterative_factorial(4));
	printf("6! = 720 --> %d\n", ft_iterative_factorial(6));
	
	printf("\n--ex01--\n");
	printf("-1! = 0 --> %d\n", ft_recursive_factorial(-1));
	printf("0! = 1 --> %d\n", ft_recursive_factorial(0));
	printf("4! = 24 --> %d\n", ft_recursive_factorial(4));
	printf("6! = 720 --> %d\n", ft_recursive_factorial(6));

	printf("\n--ex02--\n");
	printf("0 ^ -1 = 0 --> %d\n", ft_iterative_power(0,-1));
	printf("0 ^ 0 = 1 --> %d\n", ft_iterative_power(0,0));
	printf("1 ^ 0 = 1 --> %d\n", ft_iterative_power(1,0));
	printf("2 ^ 5 = 32 --> %d\n", ft_iterative_power(2,5));
	printf("-3 ^ 3 = -27 --> %d\n", ft_iterative_power(-3,3));

	printf("\n--ex03--\n");
	printf("0 ^ -1  = 0 --> %d\n", ft_recursive_power(0,-1));
	printf("0 ^ 0  = 1 --> %d\n", ft_recursive_power(0,0));
	printf("1 ^ 0  = 1 --> %d\n", ft_recursive_power(1,0));
	printf("2 ^ 5  = 32 --> %d\n", ft_recursive_power(2,5));
	printf("-3 ^ 3  = -27 --> %d\n", ft_recursive_power(-3,3));

	printf("\n--ex04--\n");
	printf("index -1 = -1 --> %d\n", ft_fibonacci(-1));
	printf("index 0 = 0 --> %d\n", ft_fibonacci(0));
	printf("index 1 = 1 --> %d\n", ft_fibonacci(1));
	printf("index 2 = 1 --> %d\n", ft_fibonacci(2));
	printf("index 3 = 2 --> %d\n", ft_fibonacci(3));
	printf("index 4 = 3 --> %d\n", ft_fibonacci(4));
	printf("index 5 = 5 --> %d\n", ft_fibonacci(5));
	printf("index 7 = 13 --> %d\n", ft_fibonacci(7));

	printf("\n--ex05--\n");
	printf("-1 = --> (%d)???\n", ft_sqrt(-1));
	printf("4 = --> (%d)^2\n", ft_sqrt(4));
	printf("7 = --> (%d)???\n", ft_sqrt(7));
	printf("1 = --> (%d)???\n", ft_sqrt(1));
	printf("225 = --> (%d)^2\n", ft_sqrt(225));

	printf("\n--ex06--\n");
	printf("0 is prime? 0 --> %d\n", ft_is_prime(0));
	printf("-1 is prime? 0 --> %d\n", ft_is_prime(-1));
	printf("1 is prime? 0 --> %d\n", ft_is_prime(1));
	printf("2 is prime? 1 --> %d\n", ft_is_prime(2));
	printf("4 is prime? 0 --> %d\n", ft_is_prime(4));
	printf("127 is prime? 1 --> %d\n", ft_is_prime(127));
	printf("1111 is prime? 1 --> %d\n", ft_is_prime(1117));

	printf("\n--ex07--\n");
	printf("next prime -1 --> %d\n", ft_find_next_prime(-1));
	printf("next prime 2 --> %d\n", ft_find_next_prime(2));
	printf("next prime 120 --> %d\n", ft_find_next_prime(120));
	printf("next prime 1111 --> %d\n", ft_find_next_prime(1111));

	printf("\n--ex08--\n");
	printf("count : %d\n", ft_ten_queens_puzzle());
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
	printf("TESTCASE IS NOT GOD\n");
}

