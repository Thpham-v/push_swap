/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:16:57 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/14 22:13:31 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_tab *tabs)
{
	if (tabs->index_a >= 2)
		ft_swap(&tabs->tab1[0], &tabs->tab1[1]);
}

void	swap_b(t_tab *tabs)
{
	if (tabs->index_b >= 2)
		ft_swap(&tabs->tab2[0], &tabs->tab2[1]);
}

void	push_a(t_tab *tabs)
{
	if (tabs->index_b)
	{
		tabs->tab1[0] = tabs->tab2[0];
		rotate_b(tabs);
		tabs->index_b--;
	}
}

void	push_b(t_tab *tabs)
{
	if (tabs->index_a)
	{
		tabs->tab2[0] = tabs->tab1[0];
		rotate_a(tabs);
		tabs->index_a--;
	}
}

