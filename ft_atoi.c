/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:33:51 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/01 22:35:50 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_atoi_help(char **s, int *i, int *si)
{
	while (((*s)[*i] >= 9 && (*s)[*i] <= 13) || (*s)[*i] == ' ')
	{
		++(*i);
	}
	if ((*s)[*i] == '+' || (*s)[*i] == '-')
	{
		if ((*s)[*i] == '-')
			*si = *si * -1;
		++(*i);
	}
}

long	ft_atoi(char *s)
{
	long	nbr;
	int		i;
	int		st;
	int		si;

	i = 0;
	si = 1;
	nbr = 0;
	ft_atoi_help(&s, &i, &si);
	if (s[i] >= '0' && s[i] <= '9')
	{
		st = i;
		while (s[i] >= '0' && s[i] <= '9')
		{
			nbr = ((10 * nbr) + (s[i] - '0'));
			++i;
		}
		if ((s[i] == '\0' || s[i] == ' '))
			if ((check_overflow(nbr, s, st, (i - 1))) > 0)
				return (nbr * si);
	}
	return (2147483648);
}
