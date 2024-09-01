/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:50:55 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/01 16:36:15 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int letter)
{
	t_stack	*tmp;
	t_stack	*bot;

	tmp = *stack;
	bot = (*stack)->prev;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next->prev = tmp;
	(*stack)->next = tmp;
	bot = tmp->prev;
	bot->next = (*stack);
	(*stack)->prev = bot;
	tmp->prev = (*stack);
	if (letter == A)
		ft_printf("sa\n");
	else if (letter == B)
		ft_printf("sb\n");
}

void	push(t_stack **src, t_stack **dest, int letter)
{
	t_stack	*tmp;

	tmp = *src;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*src = tmp->next;
	if (tmp == tmp->next)
		*src = NULL;
	if (*dest == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *dest;
		tmp->prev = (*dest)->prev;
		(*dest)->prev->next = tmp;
		(*dest)->prev = tmp;
	}
	*dest = tmp;
	if (letter == A)
		ft_printf("pa\n");
	else if (letter == B)
		ft_printf("pb\n");
}

void	rotate(t_stack **stack, int rotate, int letter)
{
	if (rotate == ROTATE)
	{
		(*stack) = (*stack)->next;
		if (letter == A)
			ft_printf("ra\n");
		else if (letter == B)
			ft_printf("rb\n");
		else if (letter == AB)
			ft_printf("rr\n");
	}
	else if (rotate == RROTATE)
	{
		(*stack) = (*stack)->prev;
		if (letter == A)
			ft_printf("rra\n");
		else if (letter == B)
			ft_printf("rrb\n");
		else if (letter == AB)
			ft_printf("rrr\n");
	}
}
