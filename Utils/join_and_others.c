/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_others.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:49:55 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/09 15:28:30 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int a)
{
	int	ret;

	ret = 0;
	if ((a >= '0' && a <= '9') || a == '-' || a == '+')
		ret = 1;
	return (ret);
}

void	*ft_calloc(int count, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i1;
	int		i2;

	i1 = -1;
	i2 = -1;
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i1])
		str[i1] = s1[i1];
	while (s2[++i2])
		str[i1++] = s2[i2];
	str[i1] = ' ';
	str[i1 + 1] = '\0';
	free((void *)s1);
	return (str);
}
