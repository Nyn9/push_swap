/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:12:14 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/01 20:13:58 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *lst)
{
	t_stack	*first;
	int		i;

	i = 0;
	first = lst;
	while (lst->next != first)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*lstnew(long content)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->n = content;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*first;

	first = lst;
	while (lst->next != first)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

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

t_stack	*fill_a(int ac, char **av)
{
	t_stack	*a;
	char	**element;
	int		i;

	i = 0;
	a = NULL;
	if (ac == 2)
	{
		element = ft_split(av[1], ' ');
		while (element[i])
		{
			lstadd_back(&a, lstnew(my_atoi(element[i])));
			error(my_atoi(element[i]), &a, element[i], element);
			i++;
		}
		freestr(element);
		free(element);
	}
	while (++i < ac)
	{
		lstadd_back(&a, lstnew(my_atoi(av[i])));
		error(my_atoi(av[i]), &a, av[i], NULL);
	}
	return (a);
}
