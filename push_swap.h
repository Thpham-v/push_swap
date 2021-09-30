/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:45:36 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/30 19:40:02 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct 	s_tab
{
	long *tab1;
	long *tab2;
	long *perfect_tab;
	int	index_a;
	int	index_b;
}				t_tab;

typedef	struct	s_var
{
	int	pos_first;
	int	pos_last;
	int	count;
	
}				t_var;


int	init_tab(int argc, char **argv, t_tab *tabs);
long	ft_atoi(const char *str);
int	ft_isdigit(char *str);
void	sort_int_tab(t_tab *tabs, int size);
void	ft_swap(long *a, long *b);
int	parsing(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
void	swap_a(t_tab *tabs);
void	swap_b(t_tab *tabs);
void	push_a(t_tab *tabs);
void	push_b(t_tab *tabs);
void	rotate_a(t_tab *tabs);
void	rotate_b(t_tab *tabs);
void	reverse_r_a(int argc, t_tab *tabs);
void	reverse_r_b(int argc, t_tab *tabs);
void	swap_a_b(t_tab *tabs);
void	rotate_a_b(t_tab *tabs);
void	reverse_r_a_b(int argc, t_tab *tabs);


#endif