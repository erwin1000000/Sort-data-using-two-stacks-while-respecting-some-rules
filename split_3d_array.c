/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_3d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:36:38 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/02 14:04:16 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	***split_3d_array(int ac, char **av)
{
	char	***p;
	int		i;

	p = (char ***)malloc(sizeof(char **) * ac);
	if (!p)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	p[ac - 1] = NULL;
	i = 1;
	while (i < ac)
	{
		p[i - 1] = ft_split(av[i], ' ');
		if (!p[i - 1])
			array_3d_gard_free(p, (i - 2));
		++i;
	}
	return (p);
}
