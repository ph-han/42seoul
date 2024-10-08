#include <stdio.h>

extern char* ft_convert_base(char* nbr, char* base_from, char* base_to);

void test_convert_base(char* nbr) {
	printf("%s => %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
}

int main() {
	test_convert_base("0");
	test_convert_base("1");
	test_convert_base("42");
	test_convert_base("-42");
	test_convert_base("2147483647");
	test_convert_base("-2147483648");

	return 0;
}
