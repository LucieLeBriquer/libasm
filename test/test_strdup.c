/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:59:36 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/01 00:59:37 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_strdup(void)
{
	char	*str1;
	char	*str2;

	printt("STRDUP");
	printst("strdup(\"Hello\")");
	str2 = ft_strdup("Hello");
	printf("mine : %s\n", str2);
	str1 = strdup("Hello");
	printf("orig : %s\n", str1);
	free(str1);
	free(str2);
	printst("free.... ok");
	printf("\n");
}
