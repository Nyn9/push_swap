/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferrad <nferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:36:40 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/01 17:33:30 by nferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *a)
{
	t_stack	*checker;
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		checker = tmp->next;
		while (checker != a)
		{
			if (checker->n == tmp->n)
			{
				write(2, "Error\nDuplicated element\n", 25);
				return (1);
			}
			checker = checker->next;
		}
		tmp = tmp->next;
		if (tmp->next == a)
			break ;
	}
	return (0);
}

int	is_sort(t_stack *stack)
{
	t_stack	*tmpa;

	tmpa = stack;
	while (tmpa)
	{
		if (tmpa->n > tmpa->next->n)
			return (0);
		tmpa = tmpa->next;
		if (tmpa->next == stack)
			break ;
	}
	return (1);
}

int	my_atoi(const char *nptr)
{
	long long int	res;
	int				sign;

	sign = 1;
	res = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13) || *nptr == '+')
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		error();
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			error();
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	if ((res * sign) > INT_MAX || (res * sign < INT_MIN))
		error();
	return (res * sign);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
