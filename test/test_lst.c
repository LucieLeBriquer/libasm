/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucie <lucie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:59:54 by lle-briq          #+#    #+#             */
/*   Updated: 2021/06/25 17:15:47 by lucie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	free_lst(t_list *begin)
{
	t_list	*save;

	while (begin)
	{
		save = begin->next;
		free(begin);
		begin = save;
	}
}

void	test_list_size(void)
{
	t_list	*begin;

	printt("LIST_SIZE AND PUSH_FRONT");
	printst("list_size(1->2->3->NULL)");
	begin = NULL;
	ft_list_push_front(&begin, "1");
	ft_list_push_front(&begin, "2");
	ft_list_push_front(&begin, "3");
	printf("size : %d\n", ft_list_size(begin));
	free_lst(begin);
	printst("list_size(NULL)");
	begin = NULL;
	printf("size : %d\n", ft_list_size(begin));
	free_lst(begin);
	printst("list_size(1->NULL)");
	begin = NULL;
	ft_list_push_front(&begin, "1");
	printf("size : %d\n", ft_list_size(begin));
	free_lst(begin);
}

int	cmp(char *str1, char *str2)
{
	if (str1[0] >= str2[0])
		return (1);
	return (0);
}

void	free_fct(void *data)
{
	(void)data;
}

void	test_list_remove_if(void)
{
	t_list	*begin;
	void	*p;

	printt("LIST_REMOVE_IF");
	printst("list_remove_if(1->2->3->NULL)");
	begin = NULL;
	ft_list_push_front(&begin, "1");
	ft_list_push_front(&begin, "2");
	ft_list_push_front(&begin, "3");
	p = ft_list_remove_if(&begin, "2", &cmp, &free_fct);
	printf("curr->data : %p\n", p);
	free_lst(begin);
}
