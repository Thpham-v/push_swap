/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:50:32 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/20 13:49:23 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_tab(int argc, char **argv, t_tab *tabs)
{
	int	i;

	i = 0;
	tabs->index_a = argc - 1;
	tabs->index_b = 0;
	tabs->tab1 = malloc(sizeof(long) * argc);
	if (!tabs->tab1)
		return (-2);
	tabs->perfect_tab = malloc(sizeof(long) * argc);
	if (!tabs->perfect_tab)
		return (-2);
	tabs->tab2 = malloc(sizeof(long) * argc);
	if (!tabs->tab2)
		return (-2);
	while (i < argc - 1)
	{
		tabs->tab1[i] = ft_atoi(argv[i + 1]);
		tabs->perfect_tab[i] = ft_atoi(argv[i + 1]);
		if (tabs->tab1[i] > 2147483647 || tabs->tab1[i] < -2147483648)
			return (-1);
		//free
		i++;
	}
	sort_int_tab(tabs, argc - 1);
	return (0);
}
