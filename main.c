/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:14 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/02 17:58:06 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_tab *tabs, t_var *var)
{
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		< tabs->tab1[2] && tabs->tab1[1] < tabs->tab1[2])
		swap_a(tabs, var);
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
	{
		swap_a(tabs, var);
		reverse_r_a(tabs, var);
	}
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] < tabs->tab1[2])
		rotate_a(tabs, var);
	if (tabs->tab1[0] < tabs->tab1[1] && tabs->tab1[0]
		< tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
	{
		swap_a(tabs, var);
		rotate_a(tabs, var);
	}
	if (tabs->tab1[0] < tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
		reverse_r_a(tabs, var);
}

void	sort_five(t_tab *tabs, t_var *var)
{
	int	i;
	int j;
	int	count;
	
	i = 0;
	count = 0;
	push_b(tabs, var);
	push_b(tabs, var);
	sort_three(tabs, var);
	
}

void	sort_small(t_tab *tabs, t_var *var, int argc)
{
	if (argc == 4)
		sort_three(tabs, var);
	if (argc == 6)
		sort_five(tabs, var);
}

int	best_chunk(t_tab *tabs, t_var *var, int argc, char **argv)
{
	int	chunk_size;
	int	save;
	int	best;

	chunk_size = 3;
	save = 1;
	while (chunk_size < 30)
	{
		if (init_tab(argc, argv, tabs) == -1)
			return (-1);
		if (is_sort(tabs) == -1)
			return (-1);
		var->chunk_size = chunk_size;
		algo(tabs, var);
		if (save == 1 || var->count_round < save)
		{
			save = var->count_round;
			best = chunk_size;
		}
		free_tab(tabs);
		chunk_size++;
	}
	return (best);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_tab	tabs;
	t_var	var;

	i = 0;
	var.display = 0;
	if (parsing(argc, argv) == -1)
		return (1);
	ret = best_chunk(&tabs, &var, argc, argv);
	if (ret == -1)
	{
		free_tab(&tabs);
		return (-1);
	}
	var.chunk_size = ret;
	if (init_tab(argc, argv, &tabs) == -1)
		return (-1);
	var.display++;
	if (argc == 4 || argc == 6)
		sort_small(&tabs, &var, argc);
	else
		algo(&tabs, &var);
	i = 0;
	while (i < tabs.index_a)
	{
		printf("tab a = %ld\n", tabs.tab1[i]);
		i++;
	}
	printf("\n");
	free_tab(&tabs);
	return (0);
}
