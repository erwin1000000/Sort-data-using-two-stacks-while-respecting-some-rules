/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_help2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:58:32 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/14 14:27:41 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	distance2(t_list *a, t_list *ta, int *top, int *bottom)
{
	int	pushed;
	int	chunk_size;

	pushed = *top;
	chunk_size = *bottom;
	*top = 0;
	while (a && (*a).index >= pushed + chunk_size)
	{
		++(*top);
		a = (*a).next;
	}
	*bottom = 0;
	while (ta && (*ta).index >= pushed + chunk_size)
	{
		++(*bottom);
		ta = (*ta).previous;
	}
}

int	push_a_to_b(t_list **a, t_list **ta, t_list **b, int chunk_size)
{
	t_list	*tb;
	int		pushed;

	pushed = 0;
	while (*a)
	{
		if (*b == NULL || (*(*b)).next == NULL)
			tb = *b;
		if ((*(*a)).index <= pushed)
		{
			push_b(a, ta, b, &tb);
			the_first_be_last_b(b, &tb);
			++pushed;
		}
		else if ((*(*a)).index <= pushed + chunk_size)
		{
			push_b(a, ta, b, &tb);
			++pushed;
		}
		else
		{
			the_first_be_last_a(a, ta);
		}
	}
	return (pushed);
}

void	distance3_max(t_list *b, t_list *tb, int *top, int *bottom)
{
	int	pushed;

	pushed = *top;
	*top = 0;
	while (b && (*b).index != pushed - 1)
	{
		++(*top);
		b = (*b).next;
	}
	*bottom = 0;
	while (tb && (*tb).index != pushed - 1)
	{
		++(*bottom);
		tb = (*tb).previous;
	}
}

void	push_b_to_a(t_list **a, t_list **ta, t_list **b, int *pushed)
{
	t_list	*tb;
	int		top;
	int		bottom;

	while (*b)
	{
		tb = get_tail(*b);
		top = *pushed;
		distance3_max(*b, tb, &top, &bottom);
		bring_up2(b, &tb, &top, &bottom);
		push_a(b, &tb, a, ta);
		--(*pushed);
	}
}
