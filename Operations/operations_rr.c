/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:51:04 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 18:03:27 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_prog *prog, int x)
{
	t_stack	*temp_end;
	t_stack	*new_last;

	if (!prog->st_a || !prog->st_a->next)
		return ;
	if (x == 1)
		write (1, "rra\n", 4);
	temp_end = lst_get_last(prog->st_a);
	new_last = lst_get_second_to_last(prog->st_a);
	temp_end->next = prog->st_a;
	new_last->next = NULL;
	prog->st_a = temp_end;
	ft_get_index(prog);
}

void	ft_rrb(t_prog *prog, int x)
{
	t_stack	*temp_end;
	t_stack	*new_last;

	if (!prog->st_b || !prog->st_b->next)
		return ;
	if (x == 1)
		write (1, "rrb\n", 4);
	temp_end = lst_get_last(prog->st_b);
	new_last = lst_get_second_to_last(prog->st_b);
	temp_end->next = prog->st_b;
	new_last->next = NULL;
	prog->st_b = temp_end;
	ft_get_index(prog);
}

void	ft_rrr(t_prog *prog)
{
	if ((prog->st_b && prog->st_b->next) || (prog->st_a && prog->st_a->next))
		write (1, "rrr\n", 4);
	ft_rra(prog, 0);
	ft_rrb(prog, 0);
}
