/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:41:23 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 10:30:05 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_input(char ***parts)
{
	long	nbr;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	while (parts[i])
	{
		j = 0;
		while (parts[i][j])
		{
			nbr = ft_atoi(parts[i][j]);
			if ((nbr > 2147483647) || (nbr < -2147483648))
			{
				array_3d_free(parts);
				write(2, "Error\n", 6);
				exit(1);
			}
			++j;
			++l;
		}
		++i;
	}
	return (l);
}

void	check_duplication(t_list *head, int *sorted, int l)
{
	int	i;

	i = 0;
	while (i < (l - 1))
	{
		if (sorted[i] != sorted[i + 1])
			++i;
		else
		{
			free(sorted);
			free_stack(head);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

int	check_overflow(long nbr, char *s, int st, int f)
{
	int	i;
	int	si;

	si = st - 1;
	while (s[st++] == '0')
	{
	}
	if ((st - 1) > f)
		return (1);
	i = 0;
	while ((st - 1) <= f)
	{
		++i;
		++st;
	}
	if (i > 10)
		return (-1);
	else if ((i == 10) && ((nbr % 10) <= 7))
		return (1);
	else if ((i == 10) && ((nbr % 10) == 8) && (s[si] == '-'))
		return (1);
	else if (i < 10)
		return (1);
	else
		return (-1);
}

int	check_if_sorted(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		if ((*head).index == i)
		{
			++i;
			head = (*head).next;
		}
		else
			return (-1);
	}
	return (1);
}
