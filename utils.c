/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:09:46 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/14 21:33:23 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_swap(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_tab(t_tab *tabs, int size)
{
	int	i;

	i = 1;
	if (size > 1)
	{
		while (i < size)
		{
			if (tabs->perfect_tab[i] < tabs->perfect_tab[i - 1])
			{
				ft_swap(&tabs->perfect_tab[i], &tabs->perfect_tab[i - 1]);
				i = 0;
			}
			i++;
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
		((unsigned char *)s)[i] = 0;
}
