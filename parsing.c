/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:44 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/30 19:15:34 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(char *str)
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
			return (-2);
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	int i;
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
				return (-1);
			j++;
		}
		if (ft_isdigit(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
