/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:51:28 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/03 18:21:34 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int element, t_stack *stack)
{
	t_stack	*current;
	int		pos;

	pos = 0;
	if (!stack)
		return (-1);
	current = stack;
	while (current)
	{
		if (element == current->n)
			return (pos);
		pos++;
		// ft_printf("n : %d // next : %d // prev : %d // element : %d\n", stack->n, stack->next->n, stack->prev->n, element);
		current = current->next;
		if (current->next == stack)
			break ;
	}
	return (pos);
}

int	stack_size(t_stack *stack)
{
	t_stack	*first;
	int		len;

	if (!stack)
		return (0);
	first = stack;
	len = 0;
	while (stack->next != first)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	good_number(int nb, t_stack *b)
{
	t_stack	*first;
	int		gn;
	int		i;

	first = b;
	gn = -20000;
	i = 0;
	while (b != first || !i)
	{
		if (b->n < nb && b->n > gn)
			gn = b->n;
		i++;
		b = b->next;
	}
	return (gn);
}

int	max(t_stack *stack)
{
	t_stack	*first;
	int		max;
	int		i;

	first = stack;
	max = stack->n;
	i = 0;
	while (stack != first || !i)
	{
		if (max < stack->n)
			max = stack->n;
		stack = stack->next;
		i++;
	}
	return (max);
}

int	min(t_stack *stack)
{
	t_stack	*first;
	int		min;
	int		i;

	first = stack;
	min = stack->n;
	i = 0;
	while (stack != first || !i)
	{
		if (min > stack->n)
			min = stack->n;
		stack = stack->next;
		i++;
	}
	return (min);
}
