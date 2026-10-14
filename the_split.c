/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:59:30 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 10:41:24 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	words_counter(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			++i;
		}
		if (!s[i])
			return (n);
		++n;
		while (s[i] != c && s[i])
		{
			++i;
		}
	}
	return (n);
}

char	*get_next_word(const char *s, char c, int *index)
{
	char	*p;
	int		i;

	while (s[*index] == c)
	{
		++(*index);
	}
	i = (*index);
	while (s[i] != c && s[i])
	{
		++i;
	}
	p = (char *)malloc((sizeof(char) * (i - (*index))) + 1);
	if (!p)
		return (NULL);
	p[i - (*index)] = '\0';
	i = 0;
	while (s[*index] != c && s[*index])
	{
		p[i] = s[*index];
		++(*index);
		++i;
	}
	return (p);
}

char	**free_pp(char **pp, int i)
{
	while (i > 0)
	{
		free(pp[i]);
		--i;
	}
	free(pp);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**pp;
	int		i;
	int		index;
	int		words_nbr;

	if (!s)
		return (NULL);
	words_nbr = words_counter(s, c);
	if (words_nbr == 0)
		return (NULL);
	pp = (char **)malloc(sizeof(char *) * (words_nbr + 1));
	pp[words_nbr] = NULL;
	if (!pp)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words_nbr)
	{
		pp[i] = get_next_word(s, c, &index);
		if (!pp[i])
			return (free_pp(pp, (i - 1)));
		++i;
	}
	return (pp);
}
