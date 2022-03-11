/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_and_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:45:05 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 14:47:24 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_index(t_prog *prog)
{
	int		i;
	t_stack	*temp;

	temp = prog->st_a;
	i = 0;
	prog = prog + 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = prog->st_b;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

t_stack	*lst_get_second_to_last(t_stack *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

t_stack	*lst_get_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	lst_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	ret;
	int		i;
	int		signe;

	signe = 1;
	ret = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		ret = ret * 10 + str[i] - 48;
		if ((ret > 2147483648 && signe == -1)
			|| (ret > 2147483647 && signe == 1))
			exit (0 * (write (2, "Error\n", 6)));
		i++;
	}
	return (ret * signe);
}
