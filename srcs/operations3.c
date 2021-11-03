/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:59:28 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/03 14:53:11 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(t_tab *tabs, int display)
{
	if (display == 1)
		display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		swap_a(tabs, display);
		swap_b(tabs, display);
	}
	if (display == 2)
	{
		printf("ss\n");
		display = 1;
	}
}

void	rotate_a_b(t_tab *tabs, int display)
{
	if (display == 1)
		display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		rotate_a(tabs, display);
		rotate_b(tabs, display);
	}
	if (display == 2)
	{
		printf("rr\n");
		display = 1;
	}
}

void	reverse_r_a_b(t_tab *tabs, int display)
{
	if (display == 1)
		display = 2;
	if (tabs->index_a >= 2 && tabs->index_b >= 2)
	{
		reverse_r_a(tabs, display);
		reverse_r_b(tabs, display);
	}
	if (display == 2)
	{
		printf("rrr\n");
		display = 1;
	}
}
