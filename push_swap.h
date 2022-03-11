/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:49 by lpuchol           #+#    #+#             */
/*   Updated: 2022/01/17 16:11:47 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack	t_stack;

struct s_stack
{
	int		index;
	int		index_sort;
	int		content;
	t_stack	*next;
};

typedef struct s_prog
{
	char	*str_arg;
	char	**tab_arg;
	int		nb_arg;
	int		*args;
	int		argc;
	char	**argv;
	t_stack	*st_a;
	t_stack	*st_b;
	int		size_a;
	int		size_b;
}				t_prog;

// join.c
int		ft_strlen(const char *str);
int		ft_isdigit(int a);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
// split.c
int		ft_free_split(char **tab);
int		ft_nb_word(char const *s, char c);
char	**ft_split(char const *s, char c);
//atoic.c
void	ft_get_index(t_prog *prog);
t_stack	*lst_get_second_to_last(t_stack *lst);
t_stack	*lst_get_last(t_stack *lst);
int		lst_size(t_stack *lst);
int		ft_atoi(const char *str);
//get_args.c
void	ft_get_index_sort(t_stack *stack_a);
void	ft_check_is_only_space(t_prog *prog);
void	ft_check_dup_or_empty(t_prog *prog, int i1, int i2);
void	ft_get_arg(t_prog *prog, int i, int j);
void	ft_init_stack(t_prog *prog);
//operations_s.c
void	ft_sa(t_prog *prog, int x);
void	ft_sb(t_prog *prog, int x);
void	ft_ss(t_prog *prog);
//operations_p.c
void	ft_pa(t_prog *prog);
void	ft_pb(t_prog *prog);
//operations_r.c
void	ft_ra(t_prog *prog, int x);
void	ft_rb(t_prog *prog, int x);
void	ft_rr(t_prog *prog);
//operations_rr.c
void	ft_rra(t_prog *prog, int x);
void	ft_rrb(t_prog *prog, int x);
void	ft_rrr(t_prog *prog);
//begin_and_lil_sort.c
int		ft_check_if_sort(t_prog *prog);
int		ft_check_if_st_a_sort(t_prog *prog);
void	ft_sort_of_3(t_prog *prog);
void	ft_sort_of_4(t_prog *prog);
void	ft_begin_sort(t_prog *prog);
//big_sort.c
void	ft_sort_of_5(t_prog *prog);
void	ft_big_sort(t_prog *prog);
//push_swap.c
void	ft_free_at_exit(t_prog *prog, int x);
#endif