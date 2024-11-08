/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:37:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/08 14:48:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_getmoves(t_stack *stk, t_stack *best)
{
	int	pos;
	int	idx;
	int	smallest;

	pos = 0;
	idx = 0;
	smallest = stk->moves;
	while (!best && stk->next)
	{
		if (stk->moves < smallest)
		{
			smallest = stk->moves;
			idx = pos;
		}
		pos++;
		stk = stk->next;
	}
	while (best && stk->next)
	{
		if (stk == best)
			return (idx);
		idx++;
		stk = stk->next;
	}
	return (idx);
}

static void	ft_both(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		ft_rotate_both(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		ft_reverserotate_both(a, b);
		pos_a++;
		pos_b++;
	}
}

static void	ft_single(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 0)
	{
		ft_rotate(a, RA);
		pos_a--;
	}
	while (pos_b > 0)
	{
		ft_rotate(b, RB);
		pos_b--;
	}
	while (pos_a < 0)
	{
		ft_reverserotate(a, RRA);
		pos_a++;
	}
	while (pos_b < 0)
	{
		ft_reverserotate(b, RRB);
	}
}

void	ft_align(t_stack **a, t_stack **b, t_stack *best)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = ft_getmoves(*a, best);
	pos_b = ft_getmoves(*b, best);
	size_a = ft_lstsize_stknode(*a);
	size_b = ft_lstsize_stknode(*b);
	if (pos_a > size_a / 2)
		pos_a -= size_a;
	if (pos_b > size_b / 2)
		pos_b -= size_b;
	if ((pos_a > 0 && pos_b > 0) || (pos_a < 0 && pos_b < 0))
		ft_both(a, b, pos_a, pos_b);
	ft_single(a, b, pos_a, pos_b);
}
