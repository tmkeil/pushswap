/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/05 22:24:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_movechunk(t_stack **stk_a, t_stack **stk_b, int pivot, int size)
{
	while (ft_rate(*stk_a, pivot, size, true) && size > 3)
	{
		ft_pushbest(stk_a, stk_b, size, 0);
		if (!stk_b || !*stk_b)
			return ;
		if ((*stk_b)->next && (*stk_b)->val < (*stk_b)->next->val)
			ft_rotate(stk_b, RB);
		size--;
	}
}

static void	ft_returnchunks(t_stack **stk_a, t_stack **stk_b, int la, int lb)
{
	ft_rate(*stk_a, 0, la, false);
	ft_rate(*stk_b, 0, lb, false);
	// printf("stack a:\n");
	// ft_lstiter_stknode(*stk_a, f);
	// printf("stack b:\n");
	// ft_lstiter_stknode(*stk_b, f);
	while (ft_rate(*stk_b, 0, lb, false) && ft_rate(*stk_a, 0, la, false))
	{
		ft_pairs(*stk_a, *stk_b);
		// printf("\n\nstack b:\n");
		// ft_lstiter_stknode(*stk_b, f);
		// printf("stack a:\n");
		// ft_lstiter_stknode(*stk_a, f);
		ft_pushbest(stk_a, stk_b, lb, 1);
		la++;
		lb--;
	}
}

static void	ft_finalsort(t_stack **stk, int size)
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

void	ft_longsort(t_stack **stk_a, t_stack **stk_b)
{
	int	pivot;
	int	size_start;
	int	size_curr;

	if (!stk_a || !*stk_a)
		return ;
	size_start = ft_lstsize_stknode(*stk_a);
	size_curr = size_start;
	while (size_curr > 3)
	{
		pivot = ft_convertpivot(*stk_a, size_start, size_curr);
		ft_movechunk(stk_a, stk_b, pivot, size_start);
		size_curr = ft_lstsize_stknode(*stk_a);
		// printf("\n\nchunk wurde gepusht.\nstack a:\n");
		// ft_lstiter_stknode(*stk_a, f);
		// printf("stack b:\n");
		// ft_lstiter_stknode(*stk_b, f);
	}
	// printf("\n\n");
	ft_shortsort(stk_a);
	// printf("\n\na short sorted:\n");
	// ft_lstiter_stknode(*stk_a, f);
	ft_returnchunks(stk_a, stk_b, size_curr, size_start - size_curr);
	// printf("\nafter returning\nstack a:\n");
	// ft_lstiter_stknode(*stk_a, f);
	// printf("\nstack b:\n");
	// ft_lstiter_stknode(*stk_b, f);
	// printf("after returning\n");
	ft_finalsort(stk_a, size_start);
}
