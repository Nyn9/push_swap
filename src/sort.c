/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:25:57 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/01 17:31:27 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_number_a(int nb, t_stack *a)
{
	t_stack	*first;
	int		gn;
	int		i;

	first = a;
	gn = 20000;
	i = 0;
	while (a != first || !i)
	{
		if (a->n > nb && a->n < gn)
			gn = a->n;
		i++;
		a = a->next;
	}
	return (gn);
}

int	get_target_b(int nb, t_stack *b)
{
	int	target_b;

	if (nb > max(b) || nb < min(b))
		target_b = max(b);
	else
		target_b = good_number(nb, b);
	return (target_b);
}

void	push_number_to_b(t_stack **a, t_stack **b)
{
	int	target_b;
	int	cheap;
	int	ror;

	while (stack_size(*a) > 2)
	{
		cheap = cheapest(a, b);
		target_b = get_target_b(cheap, *b);
		while ((*a)->n != cheap)
		{
			if (rorr(*a, cheap) == rorr2(*b, *a, target_b, cheap))
			{
				ror = rorr(*a, cheap);
				rotate(a, ror, AB);
				rotate(b, ror, -1);
			}
			else
				rotate(a, rorr(*a, cheap), A);
		}
		while ((*b)->n != target_b)
			rotate(b, rorr2(*b, *a, target_b, cheap), B);
		push(a, b, B);
	}
	sort_a(a);
	push_number_to_a(a, b);
}

void	sort_a(t_stack **a)
{
	t_stack	*mini;

	mini = *a;
	if ((*a)->next->n == min(*a))
		mini = (*a)->next;
	else if ((*a)->prev->n == min(*a))
		mini = (*a)->prev;
	if (mini->next->n == max(*a))
		swap(a, A);
	if ((*a)->prev->n != max(*a))
	{
		if (get_pos(mini->n, *a) == stack_size(*a))
			rotate(a, RROTATE, A);
		else
			rotate(a, ROTATE, A);
	}
}

void	push_number_to_a(t_stack **a, t_stack **b)
{
	int	i;
	int	size;
	int	mini;
	int	maxi;

	size = stack_size(*b);
	i = 0;
	mini = min(*a);
	maxi = max(*a);
	while (i <= size)
	{
		while (((*b)->n > maxi || (*b)->n < mini)
			&& rorr(*a, mini) != -1)
			rotate(a, rorr(*a, mini), A);
		while (((*b)->n < maxi && (*b)->n > mini)
			&& rorr(*a, good_number_a((*b)->n, *a)) != -1)
			rotate(a, rorr(*a, good_number_a((*b)->n, *a)), A);
		push(b, a, A);
		i++;
	}
	while (get_pos(min(*a), *a) != 0)
		rotate(a, rorr(*a, min(*a)), A);
}
