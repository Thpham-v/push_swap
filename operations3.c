/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:59:28 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/25 18:41:06 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(t_tab *tabs, t_var *var)
{
	if (var->display == 1)
		var->display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		swap_a(tabs, var);
		swap_b(tabs, var);
	}
	if (var->display == 2)
	{
		printf("ss\n");
		var->display = 1;
	}
}

void	rotate_a_b(t_tab *tabs, t_var *var)
{
	if (var->display == 1)
		var->display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		rotate_a(tabs, var);
		rotate_b(tabs, var);
	}
	if (var->display == 2)
	{
		printf("rr\n");
		var->display = 1;
	}
}

void	reverse_r_a_b(t_tab *tabs, t_var *var)
{
	if (var->display == 1)
		var->display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		reverse_r_a(tabs, var);
		reverse_r_b(tabs, var);
	}
	if (var->display == 2)
	{
		printf("rrr\n");
		var->display = 1;
	}
}