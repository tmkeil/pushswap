/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:41:15 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 13:00:47 by tkeil            ###   ########.fr       */
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

int	ft_pivot_down(t_list **stack)
{
	int		lower_pivot;
	int		size;
	int		*values;
	t_list	*current;
	int		i;

	i = 0;
	size = ft_lstsize(*stack);
	values = malloc(size * sizeof(int));
	current = *stack;
	while (i < size)
	{
		values[i++] = ft_atoi((char *)current->content);
		current = current->next;
	}
	ft_sort(values, size, ft_compare);
	lower_pivot = values[size / 4];
	free(values);
	return (lower_pivot);
}
