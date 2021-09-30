/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:57:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/28 16:32:31 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_tab *tabs)
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
}

void	rotate_b(t_tab *tabs)
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
}

void	reverse_r_a(int argc, t_tab *tabs)
{
	if (tabs->index_a >= 2)
	{
		while (argc - 2)
		{
			ft_swap(&tabs->tab1[argc - 3], &tabs->tab1[argc - 2]);
			argc--;
		}
	}
}

void	reverse_r_b(int argc, t_tab *tabs)
{
	if (tabs->index_b >= 2)
	{
		while (argc - 2)
		{
			ft_swap(&tabs->tab2[argc - 3], &tabs->tab2[argc - 2]);
			argc--;
		}
	}
}