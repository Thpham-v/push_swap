/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:50:32 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/24 19:42:55 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_tab(int argc, char **argv, t_tab *tabs)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	tabs->tab1 = malloc(sizeof(long int) * argc);
	if (!tabs->tab1)
		return (-2);
	tabs->tab2 = malloc(sizeof(long int) * argc);
	if (!tabs->tab2)
		return (-2);
	while (i < argc - 1)
	{
		tabs->tab1[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	if (!tabs->tab1)
		return (1);
	return (0);
}