/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:15 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 19:44:04 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_compare(int a, int b)
{
	return (a - b);
}

static void	ft_switch(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort(int *arr, int size, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (f(arr[i], arr[j]) > 0)
				ft_switch(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

int	ft_getpivot(t_stack *stack, int idx, int size)
{
	int		pivot;
	int		*values;
	int		i;

	i = 0;
	values = malloc(size * sizeof(int));
	while (i < size)
	{
		values[i++] = stack->val;
		stack = stack->next;
	}
	ft_sort(values, size, ft_compare);
	pivot = values[idx];
	return (free(values), pivot);
}

int	ft_convertpivot(t_stack *stk, int size, int n)
{
	float	m;
	float	x;
	int		pivot_idx;

	// korrekt:
	// double m = (double)(PIVOT_END_POINT - PIVOT_POINT) / (size - 3);
	// pivot_idx = (int)(PIVOT_POINT + m * (size - n));
	
	m = ((PIVOT_END_POINT - PIVOT_POINT) / (size - 3));
	x = (size - n - 3);
	pivot_idx = (int)(size * (PIVOT_POINT + m * x));
	return (ft_getpivot(stk, pivot_idx, size));
}
