/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:16:57 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/24 20:22:26 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int argc, t_tab *tabs)
{
	if (argc > 2)
		ft_swap(&tabs->tab1[0], &tabs->tab1[1]);
}

void	swap_b(int argc, t_tab *tabs)
{
	if (argc > 2)
		ft_swap(&tabs->tab2[0], &tabs->tab2[1]);
}

void	push_a(int argc, t_tab *tabs)
{
	if (argc > 2)
		tabs->tab1[0] = tabs->tab2[0];
}

void	push_b(int argc, t_tab *tabs)
{
	if (argc > 2)
		tabs->tab2[0] = tabs->tab1[0];
}

