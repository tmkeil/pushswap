/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:15 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 19:10:30 by tkeil            ###   ########.fr       */
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

int	ft_pivot(t_stack *stack)
{
	int		pivot;
	int		size;
	int		*values;
	int		i;

	i = 0;
	size = ft_lstsize_stknode(stack);
	values = malloc(size * sizeof(int));
	while (i < size)
	{
		values[i++] = stack->val;
		stack = stack->next;
	}
	ft_sort(values, size, ft_compare);
	pivot = values[(int)(PIVOT_POINT * size)];
	free(values);
	return (pivot);
}

int	ft_convertpivot(t_stack *stk, int size, int n)
{
	float	m;
	float	x;
	int		pivot;

	m = ((PIVOT_END_POINT - PIVOT_POINT) / (size - 3));
	x = (size - n - 3);
	pivot = (int)(PIVOT_POINT + m * x);
	return (pivot);
}
