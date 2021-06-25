/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucie <lucie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:42:33 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 17:17:25 by lucie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	printt(char *str)
{
	int	l;
	int	p;
	int	q;

	l = strlen(str) + 4;
	printf("\n%s", CYANB);
	p = (40 - l) / 2;
	q = 40 - l - p;
	if (p > 0 && q > 0)
	{
		printf("%.*s", p, "====================");
		printf("  %.24s  ", str);
		printf("%.*s", q, "====================");
	}
	printf("%s\n", WHITE);
}

void	printst(char *str)
{
	printf("\n%s> %s%s\n", CYAN, str, WHITE);
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
