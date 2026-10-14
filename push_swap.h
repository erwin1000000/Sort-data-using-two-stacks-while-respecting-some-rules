/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:53:58 by yabyaa            #+#    #+#             */
/*   Updated: 2026/01/07 18:04:24 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
	int				content;
}	t_list;

t_list	*newnode(int content);
t_list	*build_stack(char ***parts, t_list **tail);
t_list	*get_tail(t_list *head);

void	add_node_back(t_list **head, t_list *new);
void	check_duplication(t_list *head, int *sorted, int l);
void	free_stack(t_list *head);
void	array_3d_gard_free(char ***parts, int i);
void	sort_3(t_list **head, t_list **tail);
void	sort_3_help_help(t_list **head, t_list **tail, t_list **hold, int *i);
void	sort_4(t_list **a, t_list **ta, t_list **b, t_list **tb);
void	sort_5(t_list **a, t_list **ta, t_list **b, t_list **tb);
void	push_b_to_a(t_list **a, t_list **ta, t_list **b, int *pushed);
void	index_the_stack(t_list **a, int *sorted);
void	bring_up(t_list **head, t_list **tail, int *top, int *bottom);
void	bring_up2(t_list **head, t_list **tail, int *top, int *bottom);

void	push_a(t_list **from, t_list **t_from, t_list **to, t_list **t_to);
void	the_first_be_secound_a(t_list **head, t_list **tail);
void	the_first_be_last_a(t_list **head, t_list **tail);
void	the_last_be_first_a(t_list **head, t_list **tail);

void	push_b(t_list **from, t_list **t_from, t_list **to, t_list **t_to);
void	the_first_be_secound_b(t_list **head, t_list **tail);
void	the_first_be_last_b(t_list **head, t_list **tail);
void	the_last_be_first_b(t_list **head, t_list **tail);

void	the_first_be_last(t_list **head, t_list **tail);
void	the_last_be_first(t_list **head, t_list **tail);
void	rr(t_list **head1, t_list **tail1, t_list **head2, t_list **tail2);
void	rrr(t_list **head1, t_list **tail1, t_list **head2, t_list **tail2);

int		check_input(char ***parts);
int		words_counter(const char *s, char c);
int		ft_word_size(const char *s, char c, int word_nbr);
int		ft_word_index(const char *s, char c, int word_nbr);
int		ft_strlen(char *s);
int		check_overflow(long nbr, char *s, int st, int f);
int		push_a_to_b(t_list **a, t_list **ta, t_list **b, int chunk_size);
int		check_if_sorted(t_list *head);
int		*sorted_int_array(int l, t_list *a);

char	***split_3d_array(int ac, char **av);
char	***array_3d_free(char ***parts);
char	**ft_split(const char *s, char c);

long	ft_atoi(char *s);

#endif
