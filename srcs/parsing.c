/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:44 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/31 16:53:51 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1] || str[i + 1] == '+' || str[i + 1] == '-')
			return (-2);
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("Error\n");
			return (-2);
		}
		i++;
	}
	return (0);
}

int	is_sort(t_tab *tabs)
{
	int	i;

	i = 0;
	while (i < tabs->index_a - 1)
	{
		if (tabs->tab1[i + 1] < tabs->tab1[i])
			return (0);
		i++;
	}
	return (-1);
}

int	parsing(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 3)
		return (-1);
	while (i < argc)
	{
		j = 1;
		while (j + i < argc)
		{
			if (!ft_strcmp(argv[i], argv[j + i]))
			{
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		if (ft_isdigit(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
