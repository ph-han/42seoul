#include <stdio.h>

// #include "ex00/ft_ft.c"
// #include "ex01/ft_ultimate_ft.c"
#include "ft_swap.c"
// #include "ex03/ft_div_mod.c"
// #include "ex04/ft_ultimate_div_mod.c"
// #include "ex05/ft_putstr.c"
// #include "ex06/ft_strlen.c"
// #include "ex07/ft_rev_int_tab.c"
// #include "ex08/ft_sort_int_tab.c"

int main(void)
{
	int	i = 2;
	int	j = 24;
    printf("\n----ex02----\n");
	printf("before : %d, %d\n", i, j);
    ft_swap(&i, &j);
    printf("\nafter :  %d, %d\n순서 잘 바뀌었으면 답\n", i, j);

}
