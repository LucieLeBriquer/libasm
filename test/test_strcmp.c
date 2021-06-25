/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucie <lucie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:04:45 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 17:16:36 by lucie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_strcmp1(void)
{
	char	*s;
	char	*s2;

	printst("strcmp(\"Hello world !\", \"Hell!\")");
	s = "Hello world !";
	s2 = "Hell!";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);
}

static void	test_strcmp2(void)
{
	char	*s;
	char	*s2;

	printst("strcmp(\"H\", \"Hello\")");
	s = "H";
	s2 = "Hello";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);
}

void	test_strcmp(void)
{
	char	*s;
	char	*s2;

	printt("STRCMP");
	test_strcmp1();
	test_strcmp2();
	printst("strcmp(\"Hello\", \"Hello\")");
	s = "Hello";
	s2 = "Hello";
	errno = 0;
	printf("mine : %d", ft_strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : %d", strcmp(s, s2));
	printf("\terrno = %d\n", errno);
	printf("\n");
}
