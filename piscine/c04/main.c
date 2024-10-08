#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
//#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int	main (void)
{
	printf("\n----ex00----\n");
	char s0[20] = "Jungyki hates retry";
	printf("%s\n : 세보시면 19 글자입니다.", s0);
	printf("%d   vs   %lu : ft_strlen   vs   strlen\n", ft_strlen(s0), strlen(s0));
	printf("두 숫자가 같아야 정답.\n");

	printf("\n----ex01----\n");
	char s1[20] = "Jungyki hates retry";
	ft_putstr(s1);
	printf(" : 제가 싫어하는 것이 보이시면 정답 \n");

	printf("\n----ex02----\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(-456);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(789);
	printf("n");
	ft_putnbr(2147483647);
	printf("\n-2147483648, -456, 0, 789, 2147483647 순서로 잘 보이면 정답\n");

	printf("\n----ex03----\n");
	printf("\n%d :       ---+--+1234ab567을 넣었을 때\n", ft_atoi("      ---+--+1234ab567"));
	printf("\n%d : jungyeki(숫자가 아닌 문자열)를 넣었을 때\n", ft_atoi("jungyeki"));

	//printf("\n----ex04----\n");
	//printf("  --base에 문제가 있는 경우 : 출력되는 것이 없어야 함--\n");
	//ft_putnbr_base(123, "");
	//printf("\nnbr : 123, base : null\n");
	//ft_putnbr_base(123, "1");
	//printf("\nnbr : 123, base : 1\n");
	//ft_putnbr_base(123, "1123");
	//printf("\nnbr : 123, base : 1123\n");
	//ft_putnbr_base(123, "+123");
	//printf("\nnbr : 123, base : +123\n");
	//printf("  --base에 문제가 없는 경우 : 출력되는 것이 있어야 함--\n");
	//ft_putnbr_base(2147483647, "poneyvif");
	//printf("\nnbr : 2147483647, base : poneyvif\n");
	//ft_putnbr_base(-2147483648, "0123456789abcdef");
	//printf("\nnbr : -2147483648, base : 0123456789abcdef\n");
	//ft_putnbr_base(-342373, "jungyeki");
	//printf("\nnbr : -342373, base : jungyeki\n");

	printf("\n----ex05----\n");
	printf("  --base에 문제가 있는 경우 : 0이 출력되야 함--\n");
	printf("%d", ft_atoi_base("123", ""));
	printf("\nnbr : 123, base : null\n");
	printf("%d", ft_atoi_base("123", "1"));
	printf("\nnbr : 123, base : 1\n");
	printf("%d", ft_atoi_base("123", "1123"));
	printf("\nnbr : 123, base : 1123\n");
	printf("%d", ft_atoi_base("123", "+123"));
	printf("\nnbr : 123, base : +123\n");
	printf("  --base에 문제가 없는 경우 : 출력되는 것이 있어야 함--\n");
	printf("%d", ft_atoi_base("offffffffff", "poneyvif"));
	printf("\nstr : offffffffff, base : poneyvif\n");
	printf("%d", ft_atoi_base("-80000000","0123456789abcdef"));
	printf("\nstr : -80000000, base : 0123456789abcdef\n");
	printf("%d", ft_atoi_base("    ----++---+jungyeye0224", "jungyeki"));
	printf("\nstr :     ----++---+jungyeye0224, base : jungyeki\n");

	printf("\nC04 하시느라 고생하셨습니다.\n");
}

