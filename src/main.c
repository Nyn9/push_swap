/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:07:42 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/05 00:33:42 by clouaint         ###   ########.fr       */
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

int calculate_move(t_stack *a, t_stack *b, int number_a, int size_a, int size_b)
{
	int count = 1;
	int target_b = get_target_b(number_a, b);

	count -= double_rr(a, b, number_a, target_b, size_a);
	count += count_rotate(a, number_a, -1, size_a);
	count += count_rotate(b, target_b, rorr2(b, a, target_b, number_a, size_a), size_b);

	return count;
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

void	check_stack(t_stack *a)
{
	if (!a || is_sort(a) || is_duplicate(a) || a->next == a)
	{
		lstclear(&a);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;
	int			size_b;

	b = NULL;
	if (argc < 2)
		return (-1);
	a = fill_a(argc, argv);
	check_stack(a);
	size_a = stack_size(a);
	size_b = -1;
	if (size_a < 3)
		sort_a(&a, &b, &size_a, &size_b);
	else
	{
		push(&a, &b, B);
		push(&a, &b, B);
		size_a -= 2;
		size_b += 2;
		push_number_to_b(&a, &b, &size_a, &size_b);
		push_number_to_a(&a, &b, &size_a, &size_b);
	}
	// new_print_stack(a, b);
	lstclear(&a);
	return (0);
}
