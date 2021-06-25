/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucie <lucie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 01:05:03 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 17:16:55 by lucie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_strlen(void)
{
	char	*s;

	printt("STRLEN");
	printst("strlen(\"Lucie\")");
	s = "Lucie";
	errno = 0;
	printf("mine : [%s]\tret = %ld", s, ft_strlen(s));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\tret = %ld", s, strlen(s));
	printf("\terrno = %d\n", errno);
	printst("strlen(\"\")");
	s = "";
	errno = 0;
	printf("mine : [%s]\t\tret = %ld", s, ft_strlen(s));
	printf(" \terrno = %d\n", errno);
	errno = 0;
	printf("orig : [%s]\t\tret = %ld", s, strlen(s));
	printf(" \terrno = %d\n", errno);
	printf("\n");
}
