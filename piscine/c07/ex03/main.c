#include <stdio.h>

extern char* ft_strjoin(int size, char** strs, char* sep);

int main() {
	char* strs[15] = {"write", "a", "function", "that", "will", "concatenate",
		"all", "the", "strings", "pointed", "by", "strs", "separated", "by", "sep"};

	printf("%s\n", ft_strjoin(15, strs, " "));
	printf("%s\n", ft_strjoin(0, strs, "."));

	return 0;
}
