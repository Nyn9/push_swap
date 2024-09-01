/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:52:52 by nferrad           #+#    #+#             */
/*   Updated: 2024/08/28 15:33:18 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    lstsize(t_stack *lst)
{
    t_stack *first;
    int    i;

    i = 0;
    first = lst;
    while (lst->next != first)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

t_stack    *lstnew(long content)
{
    t_stack    *element;

    element = malloc(sizeof(t_stack));
    if (!element)
        return (NULL);
    element->n = content;
    element->next = NULL;
    element->prev = NULL;
    return (element);
}

t_stack    *lstlast(t_stack *lst)
{
    t_stack    *first;

    first = lst;
    while (lst->next != first)
        lst = lst->next;
    return (lst);
}

void    lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack    *last;

    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        new->next = new;
        new->prev = new;
    }
    else
    {
        (*lst)->prev = new;
        last = lstlast(*lst);
        new->next = last->next;
        last->next = new;
        new->prev = last;
    }
}

void new_print_stack(t_stack *a, t_stack *b)
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

void print_stack(t_stack *stack)
{
    t_stack    *first;
    int    i;

    i = 0;
    first = stack;
    while (stack && (stack != first || !i))
    {
        printf("Value: %ld\n", stack->n);
        stack = stack->next;
        i++;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    t_stack			*a;
    t_stack			*b;
    long			i;

    i = 0;
    a = NULL;
    b = NULL;
    if (argc <= 1)
        return (-1);
    while (++i < argc)
        lstadd_back(&a, lstnew(ft_atoi(argv[i])));
    push(&a, &b, B);
    push(&a, &b, B);
    push_number_to_b(&a, &b);
    push_number_to_a(&a, &b);
    new_print_stack(a, b);
    return (0);
}
