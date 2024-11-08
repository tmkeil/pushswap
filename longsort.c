/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/08 18:13:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_movechunk(t_stack **stk_a, t_stack **stk_b, int pivot, int la)
{
	int	stack_pivot;

	while (ft_rate(*stk_a, pivot, la, true) && la > 3)
	{
		ft_pushbest(stk_a, stk_b, 0);
		if (!stk_b || !*stk_b)
			return ;
		stack_pivot = (int)(0.5 * pivot);
		if (*stk_b && (*stk_b)->val < stack_pivot)
			ft_rotate(stk_b, RB);
		la--;
	}
}

static void	ft_returnchunks(t_stack **stk_a, t_stack **stk_b, int la, int lb)
{
	while (ft_rate(*stk_b, 0, lb, false) && ft_rate(*stk_a, 0, la, false))
	{
		ft_pairs(*stk_a, *stk_b);
		ft_pushbest(stk_a, stk_b, 1);
		la++;
		lb--;
	}
}

void	ft_finalsort(t_stack **stk, int size)
{
	int		val;
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *stk;
	val = tmp->val;
	if (!ft_sorted(*stk))
	{
		while (tmp)
		{
			if (tmp->val < val)
				break ;
			pos++;
			tmp = tmp->next;
		}
	}
	if (pos <= (size / 2))
	{
		while (pos--)
			ft_rotate(stk, RA);
		return ;
	}
	while (size - pos++)
		ft_reverserotate(stk, RRA);
}

void	ft_longsort(t_stack **stk_a, t_stack **stk_b, int size)
{
	int	pivot;
	int	size_curr;

	if (!stk_a || !*stk_a)
		return ;
	size_curr = ft_lstsize_stknode(stk_a);
	while (size_curr > 3)
	{
		pivot = ft_convertpivot(stk_a, size, size_curr);
		ft_movechunk(stk_a, stk_b, pivot, size_curr);
		size_curr = ft_lstsize_stknode(stk_a);
	}
	ft_shortsort(stk_a);
	ft_returnchunks(stk_a, stk_b, size_curr, size - size_curr);
	ft_finalsort(stk_a, size);
}
