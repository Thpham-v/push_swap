/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:16:57 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/19 16:25:52 by thpham-v         ###   ########.fr       */
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
	int i;

	if (tabs->index_b)
	{
		i = tabs->index_a - 1;
		while (i >= 0)
		{
			tabs->tab1[i + 1] = tabs->tab1[i];
			i--;
		}
		tabs->tab1[0] = tabs->tab2[0];
		while (i < tabs->index_b)
		{
			tabs->tab2[i] = tabs->tab2[i + 1];
			i++;
		}
		tabs->index_b--;
		tabs->index_a++;
	}
}

void	push_b(t_tab *tabs)
{
	int i;

	if (tabs->index_a)
	{
		i = tabs->index_b - 1;
		while (i >= 0)
		{
			tabs->tab2[i + 1] = tabs->tab2[i];
			i--;
		}
		tabs->tab2[0] = tabs->tab1[0];
		while (i < tabs->index_a)
		{
			tabs->tab1[i] = tabs->tab1[i + 1];
			i++;
		}
		tabs->index_a--;
		tabs->index_b++;
	}
}
