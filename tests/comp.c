#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd1;
	int fd2;
	char *line1;
	char *line2;

	fd1 = open ("dprintf_output.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("Could not open file\n");
		return 0;
	}
	fd2 = open ("ft_printf_output.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("Could not open file\n");
		return 0;
	}
	int i = 1;
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		if(strcmp(line1, line2))
			printf("bug! line %d\n", i);
		i++;
		if (line1)
			free(line1);
		if (line2)
			free(line2);
		line1 = get_next_line(fd1);
		if (line1 == NULL)
			break;
		line2 = get_next_line(fd2);
		if (line2 == NULL)
			break;
	}
	close(fd1);
	close(fd2);
	return (0);
}
