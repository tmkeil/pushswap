/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 21:23:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getmoves(t_stack *stk)
{
	int	pos;
	int	smallest;

	pos = 0;
	smallest = stk->moves;
	while (stk->next)
	{
		if (stk->moves < smallest)
		{
			smallest = stk->moves;
			pos++;
		}
		stk = stk->next;
	}
	return (pos);
}

int	ft_rate(t_stack *stk, int pivot, int size, bool back)
{
	int	idx;
	int	exists;

	idx = 0;
	exists = 0;
	while (stk)
	{
		if (stk->val < pivot || !back)
		{
			if (idx < size / 2)
				stk->moves = idx;
			else if (idx >= size / 2)
				stk->moves = size - idx;
			exists = 1;
		}
		else
			stk->moves = size;
		idx++;
	}
	return (exists);
}

void	ft_push_best(t_stack **from, t_stack **to, int size)
{
	int	pos;

	pos = ft_getmoves(*from);
	if (pos < size)
	{
		while (pos--)
			ft_rotate(from, RA);
	}
	else if (pos >= size / 2)
	{
		while (pos--)
			ft_reverserotate(from, RRA);
	}
	ft_push(from, to, PB);
}
