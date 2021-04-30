/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:42:33 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/01 00:49:19 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	printt(char *str)
{
	int	l;
	int	p;
	int	q;

	l = strlen(str) + 4;
	printf("\n%s", cyanB);
	p = (40 - l) / 2;
	q = 40 - l - p;
	if (p > 0 && q > 0)
	{
		printf("%.*s", p, "====================");
		printf("  %.24s  ", str);
		printf("%.*s", q, "====================");
	}
	printf("%s\n", white);
}

void	printst(char *str)
{
	printf("\n%s> %s%s\n", cyan, str, white);
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
	//test_list_remove_if();
	return (0);
}
