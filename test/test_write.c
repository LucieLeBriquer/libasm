/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucie <lucie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:07:29 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 17:17:03 by lucie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_write1(void)
{
	char	*s;

	printst("write(1, s, len(s))");
	s = "Hello world!";
	errno = 0;
	printf("mine :\n");
	printf("|\tret = %ld", ft_write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig :\n");
	printf("|\tret = %ld", write(1, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	printst("write on wrong file descriptor");
	errno = 0;
	printf("mine :\n");
	printf("|ret = %ld", ft_write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig :\n");
	printf("|ret = %ld", write(4, s, ft_strlen(s)));
	printf("\terrno = %d\n", errno);
}

static void	test_write2(void)
{
	char	*s;

	s = "Hello world!";
	printst("write only a part of the string");
	errno = 0;
	printf("mine :\n");
	printf("|\t ret = %ld", ft_write(1, s, 4));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig :\n");
	printf("|\t ret = %ld", write(1, s, 4));
	printf("\terrno = %d\n", errno);
	printst("overwriting");
	errno = 0;
	printf("mine :\n");
	printf("|\tret = %ld", ft_write(1, s, 20));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig :\n");
	printf("|\tret = %ld", write(1, s, 20));
	printf("\terrno = %d\n", errno);
	printf("\n");
}

void	test_write(void)
{
	printt("WRITE ");
	test_write1();
	test_write2();
	printst("NULL string");
	errno = 0;
	printf("mine :\n");
	printf("|\tret = %ld", ft_write(1, NULL, 20));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig :\n");
	printf("|\tret = %ld", write(1, NULL, 20));
	printf("\terrno = %d\n", errno);
	printf("\n");
}
