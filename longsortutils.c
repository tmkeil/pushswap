/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/06 15:43:37 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (idx <= size / 2)
				stk->moves = idx;
			else if (idx > size / 2)
				stk->moves = size - idx;
			exists = 1;
		}
		else
			stk->moves = size;
		idx++;
		stk = stk->next;
	}
	return (exists);
}

int	ft_getmoves(t_stack *stk, t_stack *fastest)
{
	int	pos;
	int	idx;
	int	smallest;

	pos = 0;
	idx = 0;
	smallest = stk->moves;
	while (!fastest && stk->next)
	{
		if (stk->moves < smallest)
		{
			smallest = stk->moves;
			idx = pos;
		}
		pos++;
		stk = stk->next;
	}
	while (fastest && stk->next)
	{
		if (stk == fastest)
			return (idx);
		idx++;
		stk = stk->next;
	}
	return (idx);
}

void	ft_align(t_stack **stk, int size, t_stack *fastest)
{
	int	pos;

	pos = ft_getmoves(*stk, fastest);
	if (pos <= size / 2)
	{
		while (pos--)
			ft_rotate(stk, RA);
	}
	else if (pos > size / 2)
	{
		while (size - pos++)
			ft_reverserotate(stk, RRA);
	}
}

void	ft_pushbest(t_stack **a, t_stack **b, int lena, int d)
{
	int		lenb;
	t_stack	*stk;

	stk = NULL;
	lenb = ft_lstsize_stknode(*b);
	if (d == 0)
	{
		ft_align(a, lena, stk);
		ft_push(a, b, PB);
	}
	else if (d == 1)
	{
		stk = ft_lstfindfastest(*b);
		ft_align(b, lenb, stk);
		ft_align(a, lena, stk->pair);
		ft_push(b, a, PA);
	}
}

void	ft_pairs(t_stack *stk_a, t_stack *stk_b)
{
	int		val;
	t_stack	*tmp;

	while (stk_b)
	{
		tmp = stk_a;
		val = INT_MAX;
		while (tmp)
		{
			if (ft_lstextreme(stk_a, 1)->val <= stk_b->val)
			{
				stk_b->pair = ft_lstextreme(stk_a, 0);
				break ;
			}
			else if (tmp->val <= val && tmp->val > stk_b->val)
			{
				stk_b->pair = tmp;
				val = tmp->val;
			}
			tmp = tmp->next;
		}
		stk_b = stk_b->next;
	}
}
