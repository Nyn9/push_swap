/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:25:57 by nferrad           #+#    #+#             */
/*   Updated: 2024/09/03 18:23:10 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_number_a(int nb, t_stack *a)
{
	int		gn;
	int		i;

	gn = 20000;
	i = 0;
	// ft_printf("%d\n", a->size);
	while (i < a->size)
	{
		ft_printf("Here !");
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
			{
				ft_printf("Here !");	
				rotate(a, rorr(*a, cheap), A);
				
			}
		}
		while ((*b)->n != target_b)
		{
			rotate(b, rorr2(*b, *a, target_b, cheap), B);
		}
		push(a, b, B);
		(*b)->size += 1;
	}
	sort_a(a);
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
	while (i <= size)
	{
		mini = min(*a);
		maxi = max(*a);
		while (((*b)->n > maxi || (*b)->n < mini)
			&& get_pos(mini, *a))
		{
			
			
			rotate(a, rorr(*a, mini), A);
		}
		while (((*b)->n < maxi && (*b)->n > mini)
			&& get_pos(good_number_a((*b)->n, *a), *a))
		{
			rotate(a, rorr(*a, good_number_a((*b)->n, *a)), A);
			// ft_printf("Here !");		
		}
		push(b, a, A);
		// new_print_stack(*a, *b);
		i++;
	}
	while (get_pos(min(*a), *a))
		rotate(a, rorr(*a, min(*a)), A);
}
