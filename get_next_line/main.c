#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check_leak(void)
{
	system("leaks a.out");
}

int main(void)
{
	int fd1 = open("./test4.txt", O_RDONLY);

	for (int i = 0; i < 10; i++)
	{
		printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, i, get_next_line(fd1));
		printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, i, get_next_line(fd1));
		printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, i, get_next_line(fd1));
		printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, i, get_next_line(fd1));
		printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, i, get_next_line(fd1));
	}
	atexit(check_leak);
	return (0);
}
