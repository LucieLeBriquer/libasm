/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:42:33 by lle-briq          #+#    #+#             */
/*   Updated: 2021/03/25 20:48:08 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define cyan "\033[36m"
#define cyanB "\033[1;36m"
#define white "\033[0m"
#include "libasm.h"
#include <errno.h>
#include <stdlib.h>

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
	errno = 0;
	printf("mine : [%s]\tret = %ld", s, ft_strlen(s));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\tret = %ld", s, strlen(s));
	printf("\terrno = %d\n", errno);

	s = "";
	errno = 0;
	printf("mine : [%s]\t\tret = %ld", s, ft_strlen(s));
	printf(" \terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\t\tret = %ld", s, strlen(s));
	printf(" \terrno = %d\n", errno);
	printf("\n");
}

void	test_strcmp(void)
{
	char *s;
	char *s2;

	printt("STRCMP");
	s = "Hello world !";
	s2 = "Hell!";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\tret = %d", s, s2, strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	s = "H";
	s2 = "Hello";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\t\t\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\t\t\tret = %d", s, s2, strcmp(s, s2));
	printf("\terrno = %d\n", errno);

	s = "Hello";
	s2 = "Hello";
	errno = 0;
	printf("mine : s1[%s], s2[%s]\t\tret = %d", s, s2, ft_strcmp(s, s2));
	printf("\t\terrno = %d\n", errno);
	errno = 0;
	printf("orig : s1[%s], s2[%s]\t\tret = %d", s, s2, strcmp(s, s2));
	printf("\t\terrno = %d\n", errno);

	printf("\n");
}

void	test_strcpy(void)
{
	char dest[20];
	char dest2[20];
	char *src;

	printt("STRCPY");
	src = "Hello world!";
	errno = 0;
	printf("orig : src[%s], dest[%s]", src, strcpy(dest, src));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("mine : src[%s], dest[%s]", src, ft_strcpy(dest2, src));
	printf("\terrno = %d\n", errno);

	src = "";
	errno = 0;
	printf("orig : src[%s], dest[%s]", src, strcpy(dest, src));
	printf("\t\t\t\terrno = %d\n", errno);
	errno = 0;
	printf("mine : src[%s], dest[%s]", src, ft_strcpy(dest2, src));
	printf("\t\t\t\terrno = %d\n", errno);
	printf("\n");
}

void	test_write(void)
{
	char	*s;

	printt("WRITE ");
	printst("write(1, s, len(s))");
	s = "Hello world!";
	errno = 0;
	printf("|\tret = %ld", ft_write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\tret = %ld", write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);

	printst("write on wrong file descriptor");
	errno = 0;
	printf("|ret = %ld", ft_write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|ret = %ld", write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);

	printst("write only a part of the string");
	errno = 0;
	printf("|\t ret = %ld", ft_write(1, s, 4));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\t ret = %ld", write(1, s, 4));
	printf("\terrno = %d\n", errno);

	printst("overwriting");
	errno = 0;
	printf("|\tret = %ld", ft_write(1, s, 20));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("|\tret = %ld", write(1, s, 20));
	printf("\terrno = %d\n", errno);
	printf("\n");
}

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

void	test_strdup(void)
{
	printt("STRDUP");
	printf("orig : %s\n", strdup("Hello"));
	printf("mine : %s\n", ft_strdup("Hello"));
	printf("\n");
}

t_list	*lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	add_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	test_list_size(void)
{
	t_list	*begin;

	begin = NULL;
	add_front(&begin, lstnew("1"));
	add_front(&begin, lstnew("2"));
	add_front(&begin, lstnew("3"));
	printt("LIST_SIZE");
	printf("size : %d\n", ft_list_size(begin));
}

int	main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_write();
	test_read();
	test_strdup();
	test_list_size();
	return (0);
}
