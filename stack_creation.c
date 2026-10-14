/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:45:36 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 10:40:52 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	build_stack_help(char ***parts, t_list **tail, t_list **head, int i)
{
	t_list	*hold;
	int		j;

	while (parts[i])
	{
		j = 0;
		while (parts[i][j])
		{
			if (!(i == 0 && j == 0))
			{	
				hold = newnode(ft_atoi(parts[i][j]));
				if (!hold)
				{
					array_3d_free(parts);
					free_stack(*head);
					write(2, "Error\n", 6);
					exit(1);
				}
				add_node_back(tail, hold);
			}
			++j;
		}
		++i;
	}
}

t_list	*build_stack(char ***parts, t_list **tail)
{
	t_list	*head;

	head = newnode(ft_atoi(parts[0][0]));
	if (!head)
	{
		array_3d_free(parts);
		write(2, "Error\n", 6);
		exit(1);
	}
	*tail = head;
	build_stack_help(parts, tail, &head, 0);
	array_3d_free(parts);
	return (head);
}

void	free_stack(t_list *head)
{
	t_list	*hold;

	while (head)
	{
		hold = head;
		head = (*head).next;
		free(hold);
	}
}
