/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:42:33 by lle-briq          #+#    #+#             */
/*   Updated: 2021/05/01 00:32:44 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	printt(char *str)
{
	printf("%s===== %s ======%s\n", cyanB, str, white);
}

void	printst(char *str)
{
	printf("%s>>> %s%s\n", cyan, str, white);
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
