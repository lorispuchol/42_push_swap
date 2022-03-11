/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:02:24 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 17:56:25 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_prog *prog, int x)
{
	t_stack	*ptr_temp;
	t_stack	*ptr_start;

	if (!prog->st_a || !prog->st_a->next)
		return ;
	if (x == 1)
		write (1, "sa\n", 3);
	ptr_start = prog->st_a->next;
	ptr_temp = prog->st_a->next->next;
	prog->st_a->next->next = prog->st_a;
	prog->st_a->next = ptr_temp;
	prog->st_a = ptr_start;
	ft_get_index(prog);
}

void	ft_sb(t_prog *prog, int x)
{
	t_stack	*ptr_temp;
	t_stack	*ptr_start;

	if (!prog->st_b || !prog->st_b->next)
		return ;
	if (x == 1)
		write (1, "sb\n", 3);
	ptr_start = prog->st_b->next;
	ptr_temp = prog->st_b->next->next;
	prog->st_b->next->next = prog->st_b;
	prog->st_b->next = ptr_temp;
	prog->st_b = ptr_start;
	ft_get_index(prog);
}

void	ft_ss(t_prog *prog)
{
	if ((prog->st_a && prog->st_a->next) || (prog->st_b && prog->st_b->next))
		write (1, "ss\n", 3);
	ft_sa(prog, 0);
	ft_sb(prog, 0);
}
