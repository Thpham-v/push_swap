/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:46:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/12 20:17:20 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	must_faster(int argc, t_var *var)
{
	if (var->pos_first < var->pos_last - argc - 1)
		
}*/

int	first_or_last(t_tab *tabs, t_var *var, int argc)
{
	var->pos_first = hold_first(tabs, var, argc);
	var->pos_last = hold_second(tabs, var, argc);
	if (var->pos_first <= (argc - var->pos_last - 2))
	{
		if (var->pos_first <= (argc - 2) / 2)
			return (1);
		else
			return (2);
	}
	else if (var->pos_first > argc - var->pos_last - 2)
	{
		if (var->pos_last <= (argc - 2) / 2)
			return (3);
		else
			return (4);
	}
	return (0);
}

int	hold_first(t_tab *tabs, t_var *var, int argc)
{
	int i;
	int j;
	 
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < var->chunk_size)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	hold_second(t_tab *tabs, t_var *var, int argc)
{
	int i;
	int j;
	
	i = argc - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < var->chunk_size)
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
				return (i);
			j++;
		}
		i--;
	}
	return (-1);
}