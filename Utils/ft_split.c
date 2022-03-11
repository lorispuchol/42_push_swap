/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:08:43 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/16 17:20:34 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free (tab);
	return (0);
}

int	ft_nb_word(char const *s, char c)
{
	int	i;
	int	nb_word;

	nb_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			nb_word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nb_word);
}

static int	ft_alloc(char **tab, char const *s, char c, int nb_word)
{
	int	i;
	int	n;
	int	size_word;

	i = 0;
	n = 0;
	size_word = 0;
	while (i < nb_word)
	{
		while (s[n] && s[n] == c)
			n++;
		while (s[n] && s[n] != c)
		{
			n++;
			size_word++;
		}
		if (size_word != 0)
			tab[i] = malloc((size_word + 1) * sizeof(char));
		if (!tab[i])
			return (ft_free_split(tab));
		size_word = 0;
		i++;
	}
	return (1);
}

static void	ft_fill(char **tab, char const *s, char c, int nb_word)
{
	int	i1;
	int	i2;
	int	n;

	i1 = 0;
	i2 = 0;
	n = 0;
	while (i1 < nb_word)
	{
		while (s[n] && s[n] == c)
			n++;
		while (s[n] && s[n] != c)
		{
			tab[i1][i2] = s[n];
			i2++;
			n++;
		}
		tab[i1][i2] = '\0';
		i2 = 0;
		i1++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	char	**tab;
	int		test;

	test = 0;
	nb_word = 0;
	if (!s)
		return (NULL);
	nb_word = ft_nb_word(s, c);
	tab = malloc((nb_word + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	test = ft_alloc(tab, s, c, nb_word);
	if (test == 0)
		return (NULL);
	ft_fill(tab, s, c, nb_word);
	tab[nb_word] = 0;
	return (tab);
}
