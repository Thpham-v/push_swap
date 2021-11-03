/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:14 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/03 17:54:06 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_is_three(t_tab *tabs, t_var *var)
{
	if (tabs->index_a == 4)
		reverse_r_a(tabs, var->display);
	reverse_r_a(tabs, var->display);
	push_a(tabs, var->display);
	reverse_r_a(tabs, var->display);
	reverse_r_a(tabs, var->display);
}

void	push_to_a(t_tab *tabs, t_var *var, int pos)
{
	if (pos == 1 || pos > tabs->index_a)
	{
		push_a(tabs, var->display);
		if (pos != 1)
			rotate_a(tabs, var->display);
	}
	else if (pos == 2)
	{
		rotate_a(tabs, var->display);
		push_a(tabs, var->display);
		reverse_r_a(tabs, var->display);
	}
	else if (pos == 3)
		pos_is_three(tabs, var);
	else if (pos == 4)
	{
		reverse_r_a(tabs, var->display);
		push_a(tabs, var->display);
		rotate_a(tabs, var->display);
		rotate_a(tabs, var->display);
	}
}

int	get_pos(t_tab *tabs, int value)
{
	int	i;

	i = 0;
	if (value < tabs->tab1[0])
		return (1);
	while (i < (tabs->index_a - 1))
	{
		if (value > tabs->tab1[i] && value < tabs->tab1[i + 1])
			return (i + 2);
		i++;
	}
	if (value > tabs->tab1[i])
		return (i + 2);
	return (0);
}

void	sort_three(t_tab *tabs, t_var *var)
{
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		< tabs->tab1[2] && tabs->tab1[1] < tabs->tab1[2])
		swap_a(tabs, var->display);
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
	{
		swap_a(tabs, var->display);
		reverse_r_a(tabs, var->display);
	}
	if (tabs->tab1[0] > tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] < tabs->tab1[2])
		rotate_a(tabs, var->display);
	if (tabs->tab1[0] < tabs->tab1[1] && tabs->tab1[0]
		< tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
	{
		swap_a(tabs, var->display);
		rotate_a(tabs, var->display);
	}
	if (tabs->tab1[0] < tabs->tab1[1] && tabs->tab1[0]
		> tabs->tab1[2] && tabs->tab1[1] > tabs->tab1[2])
		reverse_r_a(tabs, var->display);
}

void	sort_five(t_tab *tabs, t_var *var)
{
	int	i;
	int	pos;

	i = 0;
	push_b(tabs, var->display);
	push_b(tabs, var->display);
	sort_three(tabs, var);
	while (i < tabs->index_b)
	{
		pos = get_pos(tabs, tabs->tab2[i]);
		push_to_a(tabs, var, pos);
	}
}

void	sort_small(t_tab *tabs, t_var *var, int argc)
{
	if (argc == 4)
		sort_three(tabs, var);
	else if (argc == 6)
		sort_five(tabs, var);
}

int	best_chunk(t_tab *tabs, t_var *var, int argc, char **argv)
{
	int	chunk_size;
	int	save;
	int	best;

	chunk_size = 3;
	save = 1;
	while (chunk_size <= 50)
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
	{
		free_tab(&tabs);
		return (-1);
	}
	var.display++;
	if (argc == 4 || argc == 6)
		sort_small(&tabs, &var, argc);
	else
		algo(&tabs, &var);
	free_tab(&tabs);
	return (0);
}
