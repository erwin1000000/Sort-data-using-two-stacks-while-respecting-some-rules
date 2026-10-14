/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_help2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:49:09 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 17:33:47 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	the_first_be_last(t_list **head, t_list **tail)
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
	}
}

void	the_last_be_first(t_list **head, t_list **tail)
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
	}
}

void	rr(t_list **head1, t_list **tail1, t_list **head2, t_list **tail2)
{
	the_first_be_last(head1, tail1);
	the_first_be_last(head2, tail2);
	write(1, "rr\n", 3);
}

void	rrr(t_list **head1, t_list **tail1, t_list **head2, t_list **tail2)
{
	the_last_be_first(head1, tail1);
	the_last_be_first(head2, tail2);
	write(1, "rrr\n", 4);
}
