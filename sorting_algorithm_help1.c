/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_help1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:01:28 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 18:08:02 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_3_help_help(t_list **head, t_list **tail, t_list **hold, int *i)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if ((*(*head)).index == i[j])
			(*(*head)).index = j;
		else if ((*(*hold)).index == i[j])
			(*(*hold)).index = j;
		else if ((*(*tail)).index == i[j])
			(*(*tail)).index = j;
		++j;
	}
	free(i);
}
