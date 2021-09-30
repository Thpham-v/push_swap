/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:44 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/29 16:25:00 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 3)
		return (-1);
	while (i < argc)
	{
		if (ft_isdigit(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}