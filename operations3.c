/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:59:28 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/18 17:45:00 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(t_tab *tabs)
{
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		swap_a(tabs);
		swap_b(tabs);
	}
}

void	rotate_a_b(t_tab *tabs)
{
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		rotate_a(tabs);
		rotate_b(tabs);
	}
}

void	reverse_r_a_b(t_tab *tabs)
{
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		reverse_r_a(tabs);
		reverse_r_b(tabs);
	}
}