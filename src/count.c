/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:52:04 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/03 18:06:19 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rorr(t_stack *stack, int nb)
{
	int	pos;

	pos = get_pos(nb, stack);
	int size = stack_size(stack);
	if (pos == 0)
		return (-1);
	if (pos <= size / 2)
		return (ROTATE);
	else
		return (RROTATE);
}

int	rorr2(t_stack *b, t_stack *a, int nb_b, int nb_a)
{
	if (get_pos(nb_a, a)
		&& count_rotate(b, nb_b, rorr(a, nb_a)) - count_rotate(a, nb_a, -1)
		<= count_rotate(b, nb_b, -1))
		return (rorr(a, nb_a));
	return (rorr(b, nb_b));
}

int	count_rotate(t_stack *stack, int nb, int ror)
{
	int	count;
	int	pos;

	pos = get_pos(nb, stack);
	count = 0;
	if (ror == -1)
		ror = rorr(stack, nb);
	if (ror == ROTATE)
		count = pos;
	else if (ror == RROTATE)
		count = (stack->size + 1) - pos;
	return (count);
}

int	double_rr(t_stack *a, t_stack *b, int nb_a, int nb_b)
{
	int	nb_rotate;

	nb_rotate = 0;
	if (rorr(a, nb_a) != rorr2(b, a, nb_b, nb_a))
		return (nb_rotate);
	while (get_pos(nb_a, a) && get_pos(nb_b, b))
	{
		nb_rotate++;
		rotate(&b, rorr2(b, a, nb_b, nb_a), -1);
		rotate(&a, rorr(a, nb_a), -1);
	}
	return (nb_rotate);
}

int	cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	int		count;
	int		gn;
	int		prev_count;
	int		target_b;

	tmpa = *a;
	prev_count = INT_MAX;
	while (tmpa->next != *a)
	{
		count = 1;
		target_b = get_target_b(tmpa->n, *b);
		count -= double_rr(*a, *b, tmpa->n, target_b);
		count += count_rotate(*a, tmpa->n, -1);
		if (prev_count > count)
			count += count_rotate(*b, target_b, rorr2(*b, *a, target_b, tmpa->n));
		if (count < prev_count)
		{
			gn = tmpa->n;
			prev_count = count;
		}
		tmpa = tmpa->next;
	}
	return (gn);
}
