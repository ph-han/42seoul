#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* ft_strdup(char* src);

void test_strdup(char* src) {
	char* str1 = ft_strdup(src);
	char* str2 = strdup(src);

	strcmp(str1, src) == 0 && strcmp(str2, src) == 0 && strcmp(str1, str2) == 0
		? printf("OK!\n")
		: printf("Failed\n");

	free(str1);
	free(str2);
}

int main() {
	test_strdup("abc");
	test_strdup("hello");
	test_strdup("");

	return 0;
}
