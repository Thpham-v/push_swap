/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:46:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/13 16:54:52 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_pos(t_tab *tabs)
{
	int i;
	int bigger;
	int	pos;

	i = 1;
	bigger = tabs->tab2[0];
	while (i < tabs->index_b)
	{
		if (tabs->tab2[i] > bigger)
		{
			bigger = tabs->tab2[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	pos_in_b(t_tab *tabs, int value)
{
	int	i;

	i = 0;
	while (i < tabs->index_b - 1)
	{
		if (i == 0)
		{
			if (value < tabs->tab2[tabs->index_b - 1] && value > tabs->tab2[i])
				return (i);
		}
		if (value < tabs->tab2[i] && value > tabs->tab2[i + 1])
			return (i + 1);
		i++;
	}
	return (-1);
}

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
	int i;
	 
	i = 0;
	while (i < tabs->index_a)
	{
		var->j = 0 + var->count_chunk; 
		while (var->j < var->chunk_size)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[var->j])
				return (i);
			var->j++;
		}
		i++;
	}
	return (-1);
}

int	hold_second(t_tab *tabs, t_var *var)
{
	int i;
	
	i = tabs->index_a - 1;
	while (i >= 0)
	{
		var->j = 0 + var->count_chunk;
		while (var->j < var->chunk_size)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[var->j])
				return (i);
			var->j++;
		}
		i--;
	}
	return (-1);
}

void	get_value(t_tab *tabs, t_var *var)
{
	int ret;
	int	pos_b;
	
	ret = first_or_last(tabs, var);
	if (ret == 1)
	{
		var->ope.ra = var->pos_first;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_first]);
	}
	else if (ret == 2)
	{
		var->ope.rra = tabs->index_a - var->pos_last;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_last]);
	}
	if (pos_b == -1)
		pos_b = bigger_pos(tabs);
	if (pos_b <= tabs->index_b / 2)
		var->ope.rb = pos_b;
	else
		var->ope.rrb = tabs->index_b - pos_b;	
}

void	opti(t_var *var)
{
	if (var->ope.ra > var->ope.rb)
		var->ope.rr = var->ope.ra - var->ope.rb;
	else
		var->ope.rr = var->ope.rb - var->ope.ra;
	
		
}