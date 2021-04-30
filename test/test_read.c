/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:00:01 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/01 01:02:44 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_read1(void)
{
	char	buff[300];
	int		fd;
	int		res;

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
}

static void	test_read2(void)
{
	char	buff[300];
	int		res;

	printst("read on wrong fd");
	buff[0] = '\0';
	errno = 0;
	res = ft_read(-1, buff, 10);
	printf("mine : [%s]\tret = %d\terrno = %d\n", buff, res, errno);
	errno = 0;
	res = read(-1, buff, 10);
	printf("orig : [%s]\tret = %d\terrno = %d\n", buff, res, errno);
}

void		test_read(void)
{
	char	buff[300];
	int		fd;
	int		res;

	printt("READ");
	test_read1();
	test_read2();
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
