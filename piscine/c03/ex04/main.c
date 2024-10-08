#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *src, char *to_find);

int main(void)
{
	printf("\n----ex04----\n");
	char *d51 = "";
	char *d52 = "asdf";
	char *d53 = "";
	char *d54 = "jungyekim want to go home";
	char *d55 = "jungyekim want to go home";
	char *s51 = "";
	char *s52 = "";
	char *s53 = "jaungyekim want to go home";
	char *s54 = "jungyekim want to go home";
	char *s55 = "asd";
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d51, s51), strstr(d51, s51));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d52, s52), strstr(d52, s52));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d53, s53), strstr(d53, s53));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d54, s54), strstr(d54, s54));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d55, s55), strstr(d55, s55));
	printf("각 문자열이 같아야 정답\n");
}
