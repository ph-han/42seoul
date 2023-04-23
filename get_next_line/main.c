#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check_leak(void)
{
	system("leaks a.out");
}

int main(void)
{
	int fd1 = open("./test_case/test4.txt", O_RDONLY);
	char *temp;

	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 1, get_next_line(fd1));
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 2, get_next_line(fd1));
	for (; ;)
	{
		temp = get_next_line(fd1);
		if (temp == 0)
			break ;
		free(temp);
	}
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 3, get_next_line(fd1));
	close(fd1);
	fd1 = open("./test_case/test4.txt", O_RDONLY);
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 4, get_next_line(fd1));
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 5, get_next_line(fd1));
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 6, get_next_line(fd1));
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 7, get_next_line(fd1));
	printf("|| FD : %d, GNL TEST (%d): %s||\n", fd1, 8, get_next_line(fd1));
	atexit(check_leak);
	return (0);
}
