/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:14 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/25 16:53:09 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	t_tab tabs;

	i = 0;
	//verif X parsing
	init_tab(argc, argv, &tabs);
	while (i < argc - 1)
	{
		printf("%d\n", tabs.tab1[i]);
		i++;
	}
	return (0);
}