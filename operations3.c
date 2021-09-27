/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:59:28 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/25 16:48:02 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(int argc, t_tab *tabs)
{
	if (argc > 2)
	{
		swap_a(argc, tabs);
		swap_b(argc, tabs);
	}
}

void	rotate_a_b(int argc, t_tab *tabs)
{
	if (argc > 2)
	{
		rotate_a(argc, &tabs);
		rotate_b(argc, &tabs);
	}
}

void	reverse_r_a_b(int argc, t_tab *tabs)
{
	if (argc > 2)
	{
		reverse_r_a(argc, &tabs);
		reverse_r_b(argc, &tabs);
	}
}