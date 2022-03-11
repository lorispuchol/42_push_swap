/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:28:31 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 21:34:04 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index_sort(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp_2;
	int		i;

	temp = stack_a;
	temp_2 = stack_a;
	i = 0;
	while (temp)
	{
		while (temp_2)
		{
			if (temp_2->content < temp->content)
				i++;
			temp_2 = temp_2->next;
		}
		temp->index_sort = i;
		i = 0;
		temp_2 = stack_a;
		temp = temp->next;
	}
}

void	ft_check_is_only_space(t_prog *prog)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (prog->argv[++i])
	{
		if (prog->argv[i][j] == ' ')
		{
			size = ft_strlen(prog->argv[i]);
			while (j < size && prog->argv[i][j] == ' ')
			{
				j++;
				if (j == size)
					ft_free_at_exit(prog, 1);
			}
		}
		j = 0;
	}
}

void	ft_check_dup_or_empty(t_prog *prog, int i1, int i2)
{
	while (++i1 < prog->nb_arg)
	{
		while (++i2 < prog->nb_arg)
			if (prog->args[i1] == prog->args[i2])
				ft_free_at_exit(prog, 1);
		i2 = (i1 + 1);
	}
	i1 = 0;
	while (++i1 < prog->argc)
		if (prog->argv[i1][0] == '\0')
			ft_free_at_exit(prog, 1);
	i1 = 0;
	i2 = -1;
	while (prog->argv[++i1])
	{
		while (prog->argv[i1][++i2])
			if ((prog->argv[i1][i2] == '-' || prog->argv[i1][i2] == '+')
				&& (!prog->argv[i1][i2 + 1] || !(prog->argv[i1][i2 + 1] >= '0'
				&& prog->argv[i1][i2 + 1] <= '9')))
				ft_free_at_exit(prog, 1);
		i2 = -1;
	}
	ft_check_is_only_space(prog);
}

void	ft_get_arg(t_prog *prog, int i, int j)
{
	prog->str_arg = ft_calloc(1, sizeof(char));
	if (!prog->str_arg)
		return ;
	while (++i < prog->argc)
		prog->str_arg = ft_strjoin(prog->str_arg, prog->argv[i]);
	prog->tab_arg = ft_split(prog->str_arg, ' ');
	prog->nb_arg = ft_nb_word(prog->str_arg, ' ');
	i = -1;
	while (prog->tab_arg[++i])
	{
		while (prog->tab_arg[i][++j])
			if (ft_isdigit(prog->tab_arg[i][j]) == 0)
				ft_free_at_exit(prog, 1);
		j = -1;
	}
	prog->args = malloc(prog->nb_arg * sizeof(int));
	if (!prog->args)
		return ;
	i = -1;
	while (prog->tab_arg[++i])
		prog->args[i] = ft_atoi(prog->tab_arg[i]);
	ft_check_dup_or_empty(prog, -1, 0);
}

void	ft_init_stack(t_prog *prog)
{
	int		i;
	t_stack	*ptr_temp;

	ft_get_arg(prog, 0, -1);
	prog->st_b = NULL;
	prog->st_a = malloc(sizeof(t_stack));
	if (!prog->st_a)
		return ;
	prog->st_a->content = prog->args[0];
	ptr_temp = prog->st_a;
	i = 0;
	while (++i < prog->nb_arg)
	{
		ptr_temp->next = malloc(sizeof(t_stack));
		if (!ptr_temp)
			return ;
		ptr_temp = ptr_temp->next;
		ptr_temp->content = prog->args[i];
	}
	ptr_temp->next = NULL;
	ft_get_index(prog);
	ft_get_index_sort(prog->st_a);
	prog->size_a = lst_size(prog->st_a);
	prog->size_b = 0;
}
