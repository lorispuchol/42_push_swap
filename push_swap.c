/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:40 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/17 16:10:04 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_at_exit(t_prog *prog, int x)
{
	t_stack	*ptr_temp;
	t_stack	*ptr_temp_2;

	ptr_temp = prog->st_a;
	while (ptr_temp)
	{
		ptr_temp_2 = ptr_temp->next;
		free(ptr_temp);
		ptr_temp = ptr_temp_2;
	}
	ptr_temp = prog->st_b;
	while (ptr_temp)
	{
		ptr_temp_2 = ptr_temp->next;
		free(ptr_temp);
		ptr_temp = ptr_temp_2;
	}
	if (prog->str_arg)
		free (prog->str_arg);
	if (prog->args)
		free (prog->args);
	ft_free_split(prog->tab_arg);
	if (x == 1)
		write (2, "Error\n", 6);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	prog.args = NULL;
	if (argc < 2)
		exit (0);
	prog.argc = argc;
	prog.argv = argv;
	ft_init_stack(&prog);
	ft_begin_sort(&prog);
	ft_free_at_exit(&prog, 0);
}
