/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:50:32 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/31 16:02:16 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(t_tab *tabs)
{
	free(tabs->tab1);
	free(tabs->tab2);
	free(tabs->perfect_tab);
}

int	malloc_tabs(int argc, t_tab *tabs)
{
	tabs->tab1 = malloc(sizeof(long) * argc - 1);
	if (!tabs->tab1)
		return (-2);
	tabs->perfect_tab = malloc(sizeof(long) * argc - 1);
	if (!tabs->perfect_tab)
		return (-2);
	tabs->tab2 = malloc(sizeof(long) * argc - 1);
	if (!tabs->tab2)
		return (-2);
	return (0);
}

int	init_tab(int argc, char **argv, t_tab *tabs)
{
	int	i;

	tabs->index_a = argc - 1;
	tabs->index_b = 0;
	tabs->perfect_len = argc - 1;
	i = malloc_tabs(argc, tabs);
	if (i == -2)
		return (-1);
	while (i < argc - 1)
	{
		tabs->tab1[i] = ft_atoi(argv[i + 1]);
		tabs->perfect_tab[i] = ft_atoi(argv[i + 1]);
		if (tabs->tab1[i] > 2147483647 || tabs->tab1[i] < -2147483648)
		{
			printf("error\n");
			return (-1);
		}
		i++;
	}
	sort_int_tab(tabs, argc - 1);
	return (0);
}
