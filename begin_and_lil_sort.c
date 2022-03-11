/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_and_lil_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:59:51 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/17 16:13:37 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_st_a_sort(t_prog *prog)
{
	t_stack	*temp;

	temp = prog->st_a;
	while (temp && temp->next)
	{
		if (temp->next->content < temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_check_if_sort(t_prog *prog)
{
	t_stack	*temp;

	if (prog->st_b)
		return (0);
	temp = prog->st_a;
	while (temp)
	{
		if (temp->index != temp->index_sort)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort_of_3(t_prog *prog)
{
	if (ft_check_if_st_a_sort(prog) == 1)
		return ;
	if (prog->st_a->index_sort == (0 + prog->size_b))
	{
		ft_rra(prog, 1);
		ft_sa(prog, 1);
	}
	else if (prog->st_a->index_sort == (1 + prog->size_b))
	{
		if (prog->st_a->next->index_sort == (0 + prog->size_b))
			ft_sa(prog, 1);
		else
			ft_rra(prog, 1);
	}
	else if (prog->st_a->index_sort == (2 + prog->size_b))
	{
		if (prog->st_a->next->index_sort == (0 + prog->size_b))
			ft_ra(prog, 1);
		else
		{
			ft_sa(prog, 1);
			ft_rra(prog, 1);
		}
	}
}

void	ft_sort_of_4(t_prog *prog)
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
	while (prog->st_a != elem)
		ft_ra(prog, 1);
	ft_pb(prog);
	ft_sort_of_3(prog);
	ft_pa(prog);
}

void	ft_begin_sort(t_prog *prog)
{
	if (ft_check_if_sort(prog) == 1 || prog->nb_arg <= 1)
		ft_free_at_exit(prog, 0);
	else if (prog->nb_arg == 2)
		ft_sa(prog, 1);
	else if (prog->nb_arg == 3)
		ft_sort_of_3(prog);
	else if (prog->nb_arg == 4)
		ft_sort_of_4(prog);
	else if (prog->nb_arg == 5)
		ft_sort_of_5(prog);
	else
		ft_big_sort(prog);
}
