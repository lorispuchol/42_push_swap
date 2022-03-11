/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:47 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/17 16:12:08 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_of_5(t_prog *prog)
{
	int		min;
	t_stack	*elem;
	t_stack	*temp;

	temp = prog->st_a;
	min = temp->content;
	while (temp)
	{
		if (temp->content <= min)
		{
			elem = temp;
			min = temp->content;
		}
		temp = temp->next;
	}
	if (elem->index > (prog->size_a / 2))
		while (prog->st_a != elem)
			ft_rra(prog, 1);
	else
		while (prog->st_a != elem)
			ft_ra(prog, 1);
	ft_pb(prog);
	ft_sort_of_4(prog);
	ft_pa(prog);
}

void	ft_big_sort(t_prog *prog)
{
	int		i;

	while (ft_check_if_st_a_sort(prog) == 0 && !prog->st_b)
	{
		i = prog->size_a;
		while (i > 0)
		{
			if ((prog->st_a->index_sort % 2) == 0)
			{
				prog->st_a->index_sort = prog->st_a->index_sort / 2;
				ft_pb(prog);
			}
			else
			{
				prog->st_a->index_sort = prog->st_a->index_sort / 2;
				ft_ra(prog, 1);
			}
			i--;
		}
		while (prog->st_b)
			ft_pa(prog);
	}
}
