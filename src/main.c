/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:07:42 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/03 18:26:41 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_print_stack(t_stack *a, t_stack *b)
{
    int i = 0;
    t_stack *firstA = a;
    t_stack *firstB = b;
    int size = stack_size(a);
    if (stack_size(b) > size)
        size = stack_size(b);
    ft_printf("\nA\t\tB\n\n");
    while (i <= size)
    {
        if (a != firstA || !i)
        {
            ft_printf("%d", a->n);
            a = a->next;
        }
        else
            ft_printf(" ");
        ft_printf("\t\t");
        if (b && (b != firstB || !i))
        {
            ft_printf("%d", b->n);
            b = b->next;
        }
        else
            ft_printf(" ");
        ft_printf("\n");
        i++;
    }
    ft_printf("\n");
}

void	lstclear(t_stack **lst)
{
	int		i;	
	t_stack	*memory;
	t_stack	*temp;

	i = 0;
	if (!lst)
		return ;
	memory = (*lst)->next;
	while (memory != *lst)
	{
		temp = memory->next;
		free(memory);
		memory = temp;
		i++;
	}
	free(*lst);
}

void	freestr(char **lst)
{
	char	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		lst++;
		free(tmp);
	}
	free(*lst);
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	if (argc < 2)
		return (-1);
	a = fill_a(argc, argv);
	a->size = stack_size(a);
	if (!a || is_sort(a) || is_duplicate(a))
	{
		lstclear(&a);
		return (-1);
	}
	if (a->size < 3)
		sort_a(&a);
	else
	{
		push(&a, &b, B);
		ft_printf("%d\n", b->size);
		push(&a, &b, B);
		// a->size = a->size ;
		// b->size = 1;
		// push_number_to_b(&a, &b);
		// push_number_to_a(&a, &b);
	}
	new_print_stack(a, b);
	lstclear(&a);
	return (0);
}
/*

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

*/