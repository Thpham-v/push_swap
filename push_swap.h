/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:45:36 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/25 16:50:07 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct 	s_tab
{
	int *tab1;
	int *tab2;
}				t_tab;

int	init_tab(int argc, char **argv, t_tab *tabs);
int	ft_atoi(const char *str);
void	ft_swap(int *a, int *b);
void	swap_a(int argc, t_tab *tabs);
void	swap_b(int argc, t_tab *tabs);
void	push_a(int argc, t_tab *tabs);
void	push_b(int argc, t_tab *tabs);
void	rotate_a(int argc, t_tab *tabs);
void	rotate_b(int argc, t_tab *tabs);
void	reverse_r_a(int argc, t_tab *tabs);
void	reverse_r_b(int argc, t_tab *tabs);
void	swap_a_b(int argc, t_tab *tabs);
void	rotate_a_b(int argc, t_tab *tabs);
void	reverse_r_a_b(int argc, t_tab *tabs);


#endif