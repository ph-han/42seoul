#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *src, char *to_find);

int main(void)
{
	printf("\n----ex04----\n");
	char *d51 = "jungyekim want to go home";
	char *d52 = "jungyekim want to go home";
	char *s55 = "go home ";
	char *s555 = "";
	printf("    haystack : jungyeki want to go home   ,   needle : go   ,   empty needle\n");
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d51, s55), strstr(d52, s55));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d51, s555), strstr(d52, s555));
	printf("각 문자열이 같아야 정답\n");
}
