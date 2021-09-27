/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:57:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/25 16:46:23 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int argc, t_tab *tabs)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		while (i < argc - 2)
		{
			ft_swap(&tabs->tab1[i], &tabs->tab1[i + 1]);
			i++;
		}
	}
}

void	rotate_b(int argc, t_tab *tabs)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		while (i < argc - 2)
		{
			ft_swap(&tabs->tab2[i], &tabs->tab2[i + 1]);
			i++;
		}
	}
}

void	reverse_r_a(int argc, t_tab *tabs)
{
	if (argc > 2)
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
	if (argc > 2)
	{
		while (argc - 2)
		{
			ft_swap(&tabs->tab2[argc - 3], &tabs->tab2[argc - 2]);
			argc--;
		}
	}
}