/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:52:04 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/05 00:42:22 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rorr(t_stack *stack, int nb, int size)
{
	int	pos;

	pos = get_pos(nb, stack);
	if (pos == 0)
		return (-1);
	if (pos <= size / 2)
		return (ROTATE);
	else
		return (RROTATE);
}

int	rorr2(t_stack *b, t_stack *a, int nb_b, int nb_a, int size_a)
{
	int	size_b;

	size_b = stack_size(b);
	if (get_pos(nb_a, a) != 0
		&& count_rotate(b, nb_b, rorr(a, nb_a, size_a), size_b) - count_rotate(a, nb_a, -1, size_a)
		<= count_rotate(b, nb_b, -1, size_b))
		return (rorr(a, nb_a, size_a));
	return (rorr(b, nb_b, size_b));
}

int	count_rotate(t_stack *stack, int nb, int ror, int size)
{
	int	count;
	int	pos;

	count = 0;
	pos = get_pos(nb, stack);
	if (ror == -1)
		ror = rorr(stack, nb, size);
	if (ror == ROTATE)
		count = pos;
	else if (ror == RROTATE)
		count = (size + 1) - pos;
	return (count);
}

int	double_rr(t_stack *a, t_stack *b, int nb_a, int nb_b, int size_a)
{
	int	nb_rotate;

	nb_rotate = 0;
	if (rorr(a, nb_a, size_a) != rorr2(b, a, nb_b, nb_a, size_a))
		return (nb_rotate);
	while (get_pos(nb_a, a) != 0 && get_pos(nb_b, b) != 0)
	{
		nb_rotate++;
		rotate(&b, rorr2(b, a, nb_b, nb_a, size_a), -1);
		rotate(&a, rorr(a, nb_a, size_a), -1);
	}
	return (nb_rotate);
}

int	cheapest(t_stack *a, t_stack *b, int size_a, int size_b)
{
	int		count;
	long	gn;
	int		prev_count;
	int		i;
	t_stack *tmpa;

	i = 0;
	prev_count = INT_MAX;
	tmpa = a;
	while (tmpa != a || !i)
	{
		if (i < prev_count || size_a - i < prev_count)
		{
			count = calculate_move(a, b, tmpa->n, size_a, size_b);		
			if (count < prev_count)
			{
				gn = tmpa->n;
				prev_count = count;
			}
		}
		tmpa = tmpa->next;
		i++;
	}
	return (gn);
}
