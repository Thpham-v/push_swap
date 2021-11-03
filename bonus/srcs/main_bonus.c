/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:35:32 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/03 17:58:44 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

int	apply_operations(char *line, t_tab *tabs)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(tabs, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(tabs, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_a_b(tabs, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(tabs, 0);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(tabs, 0);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(tabs, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(tabs, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_a_b(tabs, 0);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_r_a(tabs, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_r_b(tabs, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_r_a_b(tabs, 0);
	else
		return (-1);
	return (0);
	
}

int	read_ope(t_tab *tabs)
{
	char	*line;
	char	*temp;

	temp = NULL;
	while (get_next_line(0, &line, &temp, 1))
	{
		if (apply_operations(line, tabs) == -1)
		{
			free(line);
			if (temp)
				free(temp);
			free_tab(tabs);
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		free(line);
	}
	if (temp)
		free(temp);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tab	tabs;

	if (parsing(argc, argv) == -1)
		return (1);
	if (init_tab(argc, argv, &tabs) == -1)
	{
		free_tab(&tabs);
		return (-1);
	}
	if (read_ope(&tabs) == 0)
	{
		if (is_sort(&tabs) == -1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		return (1);	
	free_tab(&tabs);
	return (0);
}