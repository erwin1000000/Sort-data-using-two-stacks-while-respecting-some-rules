/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:13:13 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 18:07:00 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort(int l, int **sorted)
{
	int	i;
	int	hold;

	i = 0;
	while (i < (l - 1))
	{
		if ((*sorted)[i] > (*sorted)[i + 1])
		{
			hold = (*sorted)[i];
			(*sorted)[i] = (*sorted)[i + 1];
			(*sorted)[i + 1] = hold;
			if (i > 0)
				i = i - 1;
		}
		else
			++i;
	}
}

int	*sorted_int_array(int l, t_list *a)
{
	int	i;
	int	*sorted;

	i = 0;
	sorted = (int *)malloc(sizeof(int) * l);
	if (!sorted)
	{
		free_stack(a);
		exit(1);
	}
	while (i < l)
	{
		sorted[i] = (*a).content;
		a = (*a).next;
		++i;
	}
	sort(l, &sorted);
	return (sorted);
}

void	index_the_stack(t_list **a, int *sorted)
{
	t_list	*hold;
	int		i;

	hold = *a;
	while (hold)
	{
		i = 0;
		while ((*hold).content != sorted[i])
		{
			++i;
		}
		(*hold).index = i;
		hold = (*hold).next;
	}
	free(sorted);
}

void	sort_3_help(t_list **h, t_list **t, t_list **m)
{
	if ((*(*h)).index == 0 && (*(*m)).index == 2 && (*(*t)).index == 1)
	{
		the_last_be_first_a(h, t);
		the_first_be_secound_a(h, t);
	}
	else if ((*(*h)).index == 1 && (*(*m)).index == 0 && (*(*t)).index == 2)
		the_first_be_secound_a(h, t);
	else if ((*(*h)).index == 1 && (*(*m)).index == 2 && (*(*t)).index == 0)
		the_last_be_first_a(h, t);
	else if ((*(*h)).index == 2 && (*(*m)).index == 0 && (*(*t)).index == 1)
		the_first_be_last_a(h, t);
	else if ((*(*h)).index == 2 && (*(*m)).index == 1 && (*(*t)).index == 0)
	{
		the_first_be_secound_a(h, t);
		the_last_be_first_a(h, t);
	}
}

void	sort_3(t_list **head, t_list **tail)
{
	t_list	*hold;
	int		*i;

	i = (int *)malloc(sizeof(int) * 3);
	if (!i)
	{
		free_stack(*head);
		write(2, "Error\n", 6);
		exit(1);
	}
	hold = (*(*head)).next;
	i[0] = (*(*head)).index;
	i[1] = (*hold).index;
	i[2] = (*(*tail)).index;
	sort(3, &i);
	sort_3_help_help(head, tail, &hold, i);
	sort_3_help(head, tail, &hold);
}
