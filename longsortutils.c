/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/07 22:06:02 by tkeil            ###   ########.fr       */
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

void	ft_align_em(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	s_a;
	int	s_b;

	s_a = ft_lstsize_stknode(*a);
	s_b = ft_lstsize_stknode(*b);
	if (pos_a <= s_a / 2 && pos_b <= s_b / 2)
	{
		while (pos_a-- && pos_b--)
			ft_rotate_both(a, b);
		while (pos_a--)
			ft_rotate(a, RA);
		while (pos_b--)
			ft_rotate(b, RB);
	}
	else if (pos_a > s_a / 2 && pos_b > s_b / 2)
	{
		while (s_a - pos_a++ && s_b - pos_b++)
			ft_reverserotate_both(a, b);
		while (s_a - pos_a++)
			ft_reverserotate(a, RRA);
		while (s_b - pos_b++)
			ft_reverserotate(b, RRB);
	}
}

void	ft_pushbest(t_stack **a, t_stack **b, int d)
{
	int		pos_a;
	int		pos_b;
	t_stack	*stk;

	stk = NULL;
	if (d == 0)
	{
		pos_a = ft_getmoves(*a, stk);
		ft_align_em(a, NULL, pos_a, 0);
		ft_push(a, b, PB);
	}
	else if (d == 1)
	{
		stk = ft_lstfindfastest(*b);
		pos_a = ft_getmoves(*a, stk);
		pos_b = ft_getmoves(*b, stk);
		ft_align_em(a, b, pos_a, pos_b);
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
