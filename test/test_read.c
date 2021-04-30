#include "tester.h"

void	test_read(void)
{
	char	buff[300];
	int		fd;
	int		res;

	printt("READ");

	printst("read(fd, buff, 10 < file_size)");
	buff[10] = '\0';
	fd = open("test/to_read.txt", O_RDONLY);
	errno = 0;
	res = ft_read(fd, buff, 10);
	printf("mine : [%s]\tret = %d\terrno = %d\n", buff, res, errno);
	close(fd);
	fd = open("test/to_read.txt", O_RDONLY);
	errno = 0;
	res = read(fd, buff, 10);
	printf("orig : [%s]\tret = %d\terrno = %d\n", buff, res, errno);
	close(fd);

	printst("read on wrong fd");
	buff[0] = '\0';
	errno = 0;
	res = ft_read(-1, buff, 10);
	printf("mine : [%s]\tret = %d\terrno = %d\n", buff, res, errno);
	errno = 0;
	res = read(-1, buff, 10);
	printf("orig : [%s]\tret = %d\terrno = %d\n", buff, res, errno);

	printst("read(fd, buff, 200 > file_size)");
	buff[200] = '\0';
	fd = open("test/to_read.txt", O_RDONLY);
	errno = 0;
	res = ft_read(fd, buff, 200);
	printf("mine : [%s]\n\tret = %d\terrno = %d\n", buff, res, errno);
	close(fd);
	errno = 0;
	fd = open("test/to_read.txt", O_RDONLY);
	res = read(fd, buff, 200);
	printf("orig : [%s]\n\tret = %d\terrno = %d\n", buff, res, errno);
	close(fd);

	printf("\n");
}
