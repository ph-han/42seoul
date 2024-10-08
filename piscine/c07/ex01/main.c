#include <stdio.h>
#include <stdlib.h>

extern int* ft_range(int min, int max);

void test_range(int min, int max) {
	int* range = ft_range(min, max);

	if (min >= max) {
		range == NULL ? printf("OK!\n") : printf("Failed\n");
	} else {
		int result = 1;
		for (int i = 0; i < max - min; i++) {
			result &= range[i] == min + i;
		}
		result ? printf("OK!\n") : printf("Failed\n");
	}

	free(range);
}

int main() {
	test_range(1537, -8);
    test_range(2733, 2733);
    test_range(2147483647, -2119);
        test_range(0, 0);
        test_range(0, 1);
        test_range(0, 15);
        test_range(14, 15);
        test_range(0, 0);
        test_range(7, 1);
        test_range(9, 4);
        test_range(-10, 8);
        test_range(-8, 9);
        test_range(-6, 14);
        test_range(-4, 15);
        test_range(-2, 16);
	test_range(0, 0);
	test_range(1, 3);
	test_range(100, 1024);
	test_range(1024, 100);

	return 0;
}
