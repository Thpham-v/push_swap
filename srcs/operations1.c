/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:16:57 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/03 14:51:52 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_tab *tabs, int display)
{
	if (tabs->index_a >= 2)
		ft_swap(&tabs->tab1[0], &tabs->tab1[1]);
	if (display == 1)
		printf("sa\n");
}

void	swap_b(t_tab *tabs, int display)
{
	if (tabs->index_b >= 2)
		ft_swap(&tabs->tab2[0], &tabs->tab2[1]);
	if (display == 1)
		printf("sb\n");
}

void	push_a(t_tab *tabs, int display)
{
	int	i;

	if (tabs->index_b)
	{
		i = tabs->index_a - 1;
		while (i >= 0)
		{
			tabs->tab1[i + 1] = tabs->tab1[i];
			i--;
		}
		tabs->tab1[0] = tabs->tab2[0];
		i = 0;
		while (i < tabs->index_b - 1)
		{
			tabs->tab2[i] = tabs->tab2[i + 1];
			i++;
		}
		tabs->index_b--;
		tabs->index_a++;
	}
	if (display == 1)
		printf("pa\n");
}

void	push_b(t_tab *tabs, int display)
{
	int	i;

	if (tabs->index_a)
	{
		i = tabs->index_b - 1;
		while (i >= 0)
		{
			tabs->tab2[i + 1] = tabs->tab2[i];
			i--;
		}
		tabs->tab2[0] = tabs->tab1[0];
		i = 0;
		while (i < tabs->index_a - 1)
		{
			tabs->tab1[i] = tabs->tab1[i + 1];
			i++;
		}
		tabs->index_a--;
		tabs->index_b++;
	}
	if (display == 1)
		printf("pb\n");
}
