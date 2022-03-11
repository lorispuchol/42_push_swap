/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:50:24 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 18:01:37 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_prog *prog, int x)
{
	t_stack	*temp_end;
	t_stack	*new_start;

	if (!prog->st_a || !prog->st_a->next)
		return ;
	if (x == 1)
		write (1, "ra\n", 3);
	temp_end = lst_get_last(prog->st_a);
	new_start = prog->st_a->next;
	temp_end->next = prog->st_a;
	prog->st_a->next = NULL;
	prog->st_a = new_start;
	ft_get_index(prog);
}

void	ft_rb(t_prog *prog, int x)
{
	t_stack	*temp_end;
	t_stack	*new_start;

	if (!prog->st_b || !prog->st_b->next)
		return ;
	if (x == 1)
		write (1, "rb\n", 3);
	temp_end = lst_get_last(prog->st_b);
	new_start = prog->st_b->next;
	temp_end->next = prog->st_b;
	prog->st_b->next = NULL;
	prog->st_b = new_start;
	ft_get_index(prog);
}

void	ft_rr(t_prog *prog)
{
	if ((prog->st_b && prog->st_b->next) || (prog->st_a && prog->st_a->next))
		write (1, "rr\n", 3);
	ft_ra(prog, 0);
	ft_rb(prog, 0);
}
