#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 50

int	main(int argc, char **argv)
{
	int	fd;
	char buf[BUFF_SIZE];
	int	ret;
	
	if (argc != 2)
		exit(EXIT_FAILURE);
	if(!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		printf("fd = %d\n", fd);
		printf("ret = %d\n", ret);
		printf("%s\n", buf);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
