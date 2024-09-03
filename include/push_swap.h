/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:03:09 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/03 17:21:55 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ROTATE		0
# define RROTATE	1
# define A			2
# define B			3
# define AB			4

typedef struct s_stack
{
	int				size;
	long			n;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// void print_stack(t_stack *stack);
void	new_print_stack(t_stack *a, t_stack *b);
void	swap(t_stack **stack, int letter);
void	rotate(t_stack **stack, int rotate, int letter);
void	push(t_stack **src, t_stack **dest, int letter);
int		cheapest(t_stack **a, t_stack **b);
int		max(t_stack *stack);
int		min(t_stack *stack);
int		get_pos(int element, t_stack *stack);
int		good_number(int nb, t_stack *b);
int		stack_size(t_stack *stack);
int		count_rotate(t_stack *stack, int nb, int ror);
int		get_target_b(int nb, t_stack *b);
int		rorr(t_stack *stack, int nb);
int		rorr2(t_stack *b, t_stack *a, int nb_b, int nb_a);
void	push_number(t_stack **a, t_stack **b, int target_b, int cheap);
void	sort_a(t_stack **a);
void	push_number_to_a(t_stack **a, t_stack **b);
void	push_number_to_b(t_stack **a, t_stack **b);
t_stack	*fill_a(int ac, char **av);
int		is_sort(t_stack *stack);
int		is_duplicate(t_stack *a);
int		my_atoi(char *nptr);
void	freestr(char **lst);
void	lstclear(t_stack **lst);
void	error(int nb, t_stack **stack, char *c, char **element);
int		ft_find_index(t_stack *a, int nbr);
void	assign_indexes(t_stack **a);

#endif