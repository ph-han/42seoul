#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
#include "ex08/ft_print_combn.c"

#include <stdio.h>

int main(void)
{
	printf("ex00---------------------------------------\n\n");
	ft_putchar('a');
	printf("\n\n");
	printf("ex01---------------------------------------\n");
	ft_print_alphabet();
	printf("\n\n");
	printf("ex02---------------------------------------\n\n");
	ft_print_reverse_alphabet();
	printf("\n\n");
	printf("ex03---------------------------------------\n\n");
	ft_print_numbers();
	printf("\n\n");
	printf("ex04---------------------------------------\n\n");
	ft_is_negative(3);
	printf("\n");
	ft_is_negative(0);
	printf("\n");
	ft_is_negative(-1);
	printf("\n");
	ft_is_negative('\0');
	printf("\n\n");
	printf("ex05---------------------------------------\n\n");
	ft_print_comb();
	printf("\n\n");
	printf("ex06---------------------------------------\n\n");

	ft_print_comb2();
	printf("\n\n");
	printf("ex07---------------------------------------\n\n");

	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(-2147483647);
	printf("\n");
	ft_putnbr(2147483647);
	printf("\n");
	ft_putnbr(5);
	printf("\n");
	ft_putnbr(-5);
	printf("\n");
	ft_putnbr(0);
	printf("\n\n");
	printf("ex08---------------------------------------\n\n");

	ft_print_combn(2);
	printf("\n\n");
	ft_print_combn(8);
	printf("\n\n");
	ft_print_combn(3);

	return 0;
}
