/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:15:43 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/02 14:10:06 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ope(t_tab *tabs, t_var *var)
{
	var->count_round += var->ope.rr + var->ope.ra + var->ope.rb
		+ var->ope.rrr + var->ope.rra + var->ope.rrb;
	while (var->ope.rr-- > 0)
		rotate_a_b(tabs, var);
	while (var->ope.ra-- > 0)
		rotate_a(tabs, var);
	while (var->ope.rb-- > 0)
		rotate_b(tabs, var);
	while (var->ope.rrr-- > 0)
		reverse_r_a_b(tabs, var);
	while (var->ope.rra-- > 0)
		reverse_r_a(tabs, var);
	while (var->ope.rrb-- > 0)
		reverse_r_b(tabs, var);
}

void	opti(t_var *var)
{
	if (var->ope.ra >= var->ope.rb)
	{
		var->ope.ra = var->ope.ra - var->ope.rb;
		var->ope.rr = var->ope.rb;
		var->ope.rb = 0;
	}
	else if (var->ope.rb > var->ope.ra)
	{
		var->ope.rb = var->ope.rb - var->ope.ra;
		var->ope.rr = var->ope.ra;
		var->ope.ra = 0;
	}
	if (var->ope.rra >= var->ope.rrb)
	{
		var->ope.rra = var->ope.rra - var->ope.rrb;
		var->ope.rrr = var->ope.rrb;
		var->ope.rrb = 0;
	}
	else if (var->ope.rrb > var->ope.rra)
	{
		var->ope.rrb = var->ope.rrb - var->ope.rra;
		var->ope.rrr = var->ope.rra;
		var->ope.rra = 0;
	}
}

int	bigger_pos(t_tab *tabs)
{
	int	i;
	int	bigger;
	int	pos;

	pos = 0;
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
