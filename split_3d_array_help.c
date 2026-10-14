/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_3d_array_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:40:38 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/02 14:14:02 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		++i;
	}
	return (i);
}

char	***array_3d_free(char ***parts)
{
	int	i;
	int	j;

	i = 0;
	while (parts[i])
	{
		j = 0;
		while (parts[i][j])
		{
			free(parts[i][j]);
			++j;
		}
		free(parts[i]);
		++i;
	}
	free(parts);
	return (NULL);
}

void	array_3d_gard_free(char ***parts, int i)
{
	int	j;

	while (i >= 0)
	{
		j = 0;
		while (parts[i][j])
		{
			free(parts[i][j]);
			++j;
		}
		free(parts[i]);
		--i;
	}
	free(parts);
	write(2, "Error\n", 6);
	exit(1);
}
