#include <stdio.h>
#include <stdlib.h>

extern int ft_ultimate_range(int** range, int min, int max);

void test_ultimate_range(int min, int max) {
	int** range = (int**)malloc(sizeof(int*));
	int size = ft_ultimate_range(range, min, max);

	if (min >= max) {
		*range == NULL && size == 0 ? printf("OK!\n") : printf("Failed\n");
	} else {
		int result = 1;
		result &= size == max - min;
		for (int i = 0; i < size; i++) {
			result &= (*range)[i] == min + i;
		}
		result ? printf("OK!\n") : printf("Failed\n");
	}

	free(*range);
	free(range);
}

int main() {
	test_ultimate_range(0, 0);
	test_ultimate_range(1, 3);
	test_ultimate_range(100, 1024);
	test_ultimate_range(1024, 100);

	return 0;
}
