#include <stdio.h>

extern char** ft_split(char* str, char* charset);

void test_split(char* str, char *charset) {
	char** arr = ft_split(str, charset);
	for (int i = 0; arr[i] != NULL; i++) {
		printf("%s\n", arr[i]);
	}
}

int main(int argc, char* argv[]) {

	if (argc == 3) {
		test_split(argv[1], argv[2]);
	}

	return 0;
}
