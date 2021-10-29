/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:46:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/29 14:27:28 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_or_last(t_tab *tabs, t_var *var)
{
	var->pos_first = hold_first(tabs, var);
	var->pos_last = hold_second(tabs, var);
	if (var->pos_first == -1 || var->pos_last == -1)
		return (-1);
	if (var->pos_first <= (tabs->index_a - var->pos_last))
		return (1);
	return (2);
}

int	hold_first(t_tab *tabs, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < tabs->index_a)
	{
		j = var->chunk_size * var->count_chunk;
		while (j < var->chunk_size * (var->count_chunk + 1)
			&& j < tabs->perfect_len)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	hold_second(t_tab *tabs, t_var *var)
{
	int	i;
	int	j;

	i = tabs->index_a - 1;
	while (i >= 0)
	{
		j = var->chunk_size * var->count_chunk;
		while (j < var->chunk_size * (var->count_chunk + 1)
			&& j < tabs->perfect_len)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
				return (i);
			j++;
		}
		i--;
	}
	return (-1);
}

void	get_value(t_tab *tabs, t_var *var)
{
	int	ret;
	int	pos_b;

	ft_bzero(&var->ope, sizeof(t_ope));
	ret = first_or_last(tabs, var);
	if (ret == 1)
	{
		var->ope.ra = var->pos_first;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_first]);
	}
	if (ret == 2)
	{
		var->ope.rra = tabs->index_a - var->pos_last;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_last]);
	}
	if (pos_b == -1)
		pos_b = bigger_pos(tabs);
	if (pos_b <= (tabs->index_b / 2))
		var->ope.rb = pos_b;
	else
		var->ope.rrb = tabs->index_b - pos_b;
	opti(var);
}

int	algo(t_tab *tabs, t_var *var)
{
	int	ret;
	int	i;

	i = 1;
	var->count_chunk = 0;
	var->count_round = 0;
	while (tabs->index_a > 0)
	{
		get_value(tabs, var);
		apply_ope(tabs, var);
		push_b(tabs, var);
		if (i == var->chunk_size * (var->count_chunk + 1))
			var->count_chunk++;
		i++;
	}
	ft_bzero(&var->ope, sizeof(t_ope));
	ret = bigger_pos(tabs);
	if (ret <= (tabs->index_b / 2))
		var->ope.rb = ret;
	else
		var->ope.rrb = tabs->index_b - ret;
	apply_ope(tabs, var);
	while (tabs->index_b > 0)
		push_a(tabs, var);
	return (0);
}
