/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_help.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:08:25 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/14 14:28:30 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	bring_up2(t_list **head, t_list **tail, int *top, int *bottom)
{	
	if (*top <= *bottom)
	{
		while (*top > 0)
		{
			the_first_be_last_b(head, tail);
			--(*top);
		}
	}
	else
	{
		while (*bottom >= 0)
		{
			the_last_be_first_b(head, tail);
			--(*bottom);
		}
	}
}

void	bring_up(t_list **head, t_list **tail, int *top, int *bottom)
{	
	*bottom = *bottom + 1 - 1;
	while (*top > 0)
	{
		the_first_be_last_a(head, tail);
		--(*top);
	}
}

void	distance(t_list *head, t_list *tail, int *top, int *bottom)
{
	int	i;

	i = *top;
	*top = 0;
	while ((*head).index != i)
	{
		++(*top);
		head = (*head).next;
	}
	*bottom = 0;
	while ((*tail).index != i)
	{
		++(*bottom);
		tail = (*tail).previous;
	}
}

void	sort_4(t_list **a, t_list **ta, t_list **b, t_list **tb)
{
	int	top;
	int	bottom;

	top = 0;
	distance(*a, *ta, &top, &bottom);
	bring_up(a, ta, &top, &bottom);
	push_b(a, ta, b, tb);
	sort_3(a, ta);
	push_a(b, tb, a, ta);
}

void	sort_5(t_list **a, t_list **ta, t_list **b, t_list **tb)
{
	int	i;
	int	top;
	int	bottom;

	i = 0;
	while (i < 2)
	{
		top = i;
		distance(*a, *ta, &top, &bottom);
		bring_up(a, ta, &top, &bottom);
		push_b(a, ta, b, tb);
		++i;
	}
	sort_3(a, ta);
	push_a(b, tb, a, ta);
	push_a(b, tb, a, ta);
}
