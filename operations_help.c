/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:19:57 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 10:49:29 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	the_last_be_first_b(t_list **head, t_list **tail)
{
	t_list	*hold;

	if (*head != *tail)
	{
		hold = (*(*tail)).previous;
		(*hold).next = NULL;
		(*(*tail)).previous = NULL;
		(*(*tail)).next = *head;
		(*(*head)).previous = *tail;
		*head = *tail;
		*tail = hold;
		write(1, "rrb\n", 4);
	}
}

void	the_first_be_last_b(t_list **head, t_list **tail)
{
	t_list	*hold;

	if (*head != *tail)
	{
		hold = (*(*head)).next;
		(*hold).previous = NULL;
		(*(*head)).next = NULL;
		(*(*head)).previous = *tail;
		(*(*tail)).next = *head;
		*tail = *head;
		*head = hold;
		write(1, "rb\n", 3);
	}
}

void	push_b(t_list **from, t_list **t_from, t_list **to, t_list **t_to)
{
	t_list	*hold;

	hold = *from;
	*from = (*(*from)).next;
	if (*from)
		(*(*from)).previous = NULL;
	else
		*t_from = *from;
	(*hold).next = *to;
	if (*to)
		(*(*to)).previous = hold;
	*to = hold;
	if (!((*(*to)).next))
		*t_to = *to;
	write(1, "pb\n", 3);
}

void	the_first_be_secound_b(t_list **head, t_list **tail)
{
	t_list	*hold;

	hold = (*(*head)).next;
	if (hold)
	{
		(*(*head)).next = (*hold).next;
		if ((*hold).next)
			(*((*hold).next)).previous = *head;
		(*hold).next = *head;
		(*hold).previous = NULL;
		(*(*head)).previous = hold;
		if ((*(*head)).next == NULL)
			*tail = *head;
		*head = hold;
		write(1, "sb\n", 3);
	}
}
