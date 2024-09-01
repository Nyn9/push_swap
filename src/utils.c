/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:51:28 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/01 16:41:16 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int element, t_stack *stack)
{
	t_stack	*first;
	int		position;

	if (!stack)
		return (-1);
	position = 0;
	first = stack;
	while (stack->next != first)
	{
		if (stack->n == element)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
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
