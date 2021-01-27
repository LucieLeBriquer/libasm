#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define cyan "\033[36m"
#define cyanB "\033[1;36m"
#define white "\033[0m"

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_write(int fd, char *buff, int nb);
size_t	ft_read(int fd, char *buff, int nb);
char	*ft_strdup(char *src);

void	printt(char *str)
{
	printf("%s---> FT_%s <---%s\n", cyanB, str, white);
}

void	printst(char *str)
{
	printf("%s>>> %s%s\n", cyan, str, white);
}

void	test_strlen(void)
{
	char *s;

	printt("STRLEN");
	s = "Hello world !";
	printf("orig : [%s], %d\n", s, ft_strlen(s));
	printf("mine : [%s], %d\n", s, ft_strlen(s));
	s = "";
	printf("orig : [%s], %d\n", s, ft_strlen(s));
	printf("mine : [%s], %d\n", s, ft_strlen(s));
	printf("\n");
}

void	test_strcmp(void)
{
	char *s;
	char *s2;

	printt("STRCMP");
	s = "Hello world !";
	s2 = "Hell!";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	s = "H";
	s2 = "Hello";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	s = "Hello";
	s2 = "Hello";
	printf("mine : [%s], [%s], %d\n", s, s2, ft_strcmp(s, s2));
	printf("orig : [%s], [%s], %d\n", s, s2, strcmp(s, s2));
	printf("\n");
}

void	test_strcpy(void)
{
	char dest[20];
	char dest2[20];
	char *src;

	printt("STRCPY");
	src = "Bonjour bonjour";
	printf("orig : src[%s], dest[%s]\n", src, strcpy(dest, src));
	printf("mine : src[%s], dest[%s]\n", src, ft_strcpy(dest2, src));
	src = "";
	printf("orig : src[%s], dest[%s]\n", src, strcpy(dest, src));
	printf("mine : src[%s], dest[%s]\n", src, ft_strcpy(dest2, src));
	printf("\n");
}

void	test_write(void)
{
	char	*s;

	printt("WRITE ");
	printst("write(1, s, len(s))");
	s = "Hello world!";
	printf("\t%ld\n", ft_write(1, s, ft_strlen(s)));
	printf("\t%ld\n", write(1, s, ft_strlen(s)));
	printst("write on wrong file descriptor");
	printf("\t%ld\n", ft_write(4, s, ft_strlen(s)));
	printf("\t%ld\n", write(4, s, ft_strlen(s)));
	printst("write only a part of the string");
	printf("\t%ld\n", ft_write(1, s, 4));
	printf("\t%ld\n", write(1, s, 4));
	printst("overwriting");
	printf("\t%ld\n", ft_write(1, s, 20));
	printf("\t%ld\n", write(1, s, 20));
	printf("\n");
}

void	test_read(void)
{
	char	buff[300];
	int		fd;

	printt("READ");
	printst("read(fd, buff, 10 < file_size)");
	fd = open("to_read.txt", O_RDONLY);
	buff[10] = '\0';
	printf("mine : %ld", ft_read(fd, buff, 10));
	printf("\t[%s]\n", buff);
	close(fd);
	fd = open("to_read.txt", O_RDONLY);
	printf("orig : %ld", read(fd, buff, 10));
	printf("\t[%s]\n", buff);
	close(fd);
	printst("read on wrong fd");
	buff[0] = '\0';
	printf("mine : %ld", ft_read(fd + 1, buff, 10));
	printf("\t[%s]\n", buff);
	close(fd);
	fd = open("to_read.txt", O_RDONLY);
	buff[10] = '\0';
	printf("orig : %ld", read(fd + 1, buff, 10));
	printf("\t[%s]\n", buff);
	close(fd);
	printst("read(fd, buff, 200 > file_size)");
	fd = open("to_read.txt", O_RDONLY);
	buff[200] = '\0';
	printf("mine : %ld", ft_read(fd, buff, 200));
	printf("\t[%s]\n", buff);
	close(fd);
	fd = open("to_read.txt", O_RDONLY);
	printf("orig : %ld", read(fd, buff, 200));
	printf("\t[%s]\n", buff);
	close(fd);
	printf("\n");
}

void	test_strdup(void)
{
	printt("STRDUP");
	printf("orig : %s\n", strdup("Hello"));
	printf("mine : %s\n", ft_strdup("Hello"));
	printf("\n");
}

int	main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_write();
	test_read();
	test_strdup();
	return (0);
}
