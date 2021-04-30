/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:56:46 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/01 01:14:59 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_strcpy(void)
{
	char dest[20];
	char dest2[20];
	char *src;

	printt("STRCPY");
	printst("strcpy(\"Hello world!\", dest)");
	src = "Hello world!";
	errno = 0;
	printf("mine : dest[%s]", ft_strcpy(dest2, src));
	printf("\terrno = %d\n", errno);
	errno = 0;
	printf("orig : dest[%s]", strcpy(dest, src));
	printf("\terrno = %d\n", errno);
	src = "";
	printst("strcpy(\"\", dest)");
	errno = 0;
	printf("mine : dest[%s]", ft_strcpy(dest2, src));
	printf("\t\t\t\terrno = %d\n", errno);
	errno = 0;
	printf("orig : dest[%s]", strcpy(dest, src));
	printf("\t\t\t\terrno = %d\n", errno);
	printf("\n");
}
