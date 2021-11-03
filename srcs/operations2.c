/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:57:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/03 14:52:22 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_tab *tabs, int display)
{
	int	i;

	i = 0;
	if (tabs->index_a >= 2)
	{
		while (i < tabs->index_a - 1)
		{
			ft_swap(&tabs->tab1[i], &tabs->tab1[i + 1]);
			i++;
		}
	}
	if (display == 1)
		printf("ra\n");
}

void	rotate_b(t_tab *tabs, int display)
{
	int	i;

	i = 0;
	if (tabs->index_b >= 2)
	{
		while (i < tabs->index_b - 1)
		{
			ft_swap(&tabs->tab2[i], &tabs->tab2[i + 1]);
			i++;
		}
	}
	if (display == 1)
		printf("rb\n");
}

void	reverse_r_a(t_tab *tabs, int display)
{
	int	i;

	i = tabs->index_a - 1;
	if (tabs->index_a >= 2)
	{
		while (i > 0)
		{
			ft_swap(&tabs->tab1[i - 1], &tabs->tab1[i]);
			i--;
		}
	}
	if (display == 1)
		printf("rra\n");
}

void	reverse_r_b(t_tab *tabs, int display)
{
	int	i;

	i = tabs->index_b - 1;
	if (tabs->index_b >= 2)
	{
		while (i > 0)
		{
			ft_swap(&tabs->tab2[i - 1], &tabs->tab2[i]);
			i--;
		}
	}
	if (display == 1)
		printf("rrb\n");
}
