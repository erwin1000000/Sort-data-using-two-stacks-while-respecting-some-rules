/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list_fonctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:22:33 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 10:34:33 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*newnode(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	(*node).content = content;
	(*node).previous = NULL;
	(*node).next = NULL;
	return (node);
}

void	add_node_back(t_list **tail, t_list *new)
{
	(*(*tail)).next = new;
	(*new).previous = *tail;
	*tail = new;
}

t_list	*get_tail(t_list *head)
{
	while ((*head).next)
	{
		head = (*head).next;
	}
	return (head);
}
