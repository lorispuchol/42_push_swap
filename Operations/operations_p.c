/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:49:07 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 17:57:59 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_prog *prog)
{
	t_stack	*temp;

	if (!prog->st_b)
		return ;
	write(1, "pa\n", 3);
	temp = prog->st_b;
	prog->st_b = prog->st_b->next;
	temp->next = prog->st_a;
	prog->st_a = temp;
	ft_get_index(prog);
	prog->size_a++;
	prog->size_b--;
}

void	ft_pb(t_prog *prog)
{
	t_stack	*temp;

	if (!prog->st_a)
		return ;
	write (1, "pb\n", 3);
	temp = prog->st_a;
	prog->st_a = prog->st_a->next;
	temp->next = prog->st_b;
	prog->st_b = temp;
	ft_get_index(prog);
	prog->size_b++;
	prog->size_a--;
}
