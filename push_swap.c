/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:31:15 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/14 14:32:25 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap_help(int size, t_list **a, t_list **ta)
{
	t_list	*b;
	t_list	*tb;
	int		pushed;

	b = NULL;
	tb = NULL;
	if (size == 2)
		the_first_be_secound_a(a, ta);
	else if (size == 3)
		sort_3(a, ta);
	else if (size == 4)
		sort_4(a, ta, &b, &tb);
	else if (size == 5)
		sort_5(a, ta, &b, &tb);
	else
	{
		if (size <= 100)
			size = 14;
		else if (size <= 500)
			size = 35;
		else
			size = 75;
		pushed = push_a_to_b(a, ta, &b, size);
		push_b_to_a(a, ta, &b, &pushed);
	}
}

void	push_swap(char ***parts)
{
	t_list	*a;
	t_list	*ta;
	int		*sorted;
	int		size;

	size = check_input(parts);
	a = build_stack(parts, &ta);
	sorted = sorted_int_array(size, a);
	check_duplication(a, sorted, size);
	index_the_stack(&a, sorted);
	if (check_if_sorted(a) < 0)
	{
		push_swap_help(size, &a, &ta);
	}
	free_stack(a);
}

int	main(int ac, char *av[])
{
	char	***parts;

	if (ac > 1)
	{
		parts = split_3d_array(ac, av);
		push_swap(parts);
	}
	return (0);
}
