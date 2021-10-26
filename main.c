/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:14 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/26 17:35:38 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_chunk(t_tab *tabs, t_var *var, int argc, char **argv)
{
	int chunk_size;
	int	save;
	int	best;
	
	chunk_size = 3;
	save = 1;
	while (chunk_size < 30)
	{
		if (init_tab(argc, argv, tabs) == -1)
			return (-1);
		var->chunk_size = chunk_size;
		algo(tabs, var);
		if (save == 1 || var->count_round < save)
		{
			save = var->count_round;
			best = chunk_size;
		}
		free(tabs->tab1);
		free(tabs->tab2);
		free(tabs->perfect_tab);
		chunk_size++;
	}
	return (best);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_tab	tabs;
	t_var	var;

	i = 0;
	var.display = 0;
	if (parsing(argc, argv) == -1)
		return (1);
	 ret = best_chunk(&tabs, &var, argc, argv);
	 if (ret == -1)
		return (1);
	var.chunk_size = ret;
	if (init_tab(argc, argv, &tabs) == -1)
			return (-1);
	var.display++;
	algo(&tabs, &var);
	/*while (i < argc - 1)
	{
		printf("perfect = %ld\n", tabs.perfect_tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < tabs.index_a)
	{
		printf("tab a = %ld\n", tabs.tab1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < tabs.index_b)
	{
		printf("tab b = %ld\n", tabs.tab2[i]);
		i++;
	}*/
	return (0);
}
