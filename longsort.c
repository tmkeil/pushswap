/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 21:17:45 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_movechunk(t_stack **stk_a, t_stack **stk_b, int pivot, int size)
{
	while (ft_rate(*stk_a, pivot, size, true))
	{
		ft_push_best(stk_a, stk_b, size);
		if (!stk_b || !*stk_b)
			return ;
		if ((*stk_b)->next && (*stk_b)->val < (*stk_b)->next->val)
			ft_rotate(stk_b, RB);
	}
}

void	ft_returnchunks(t_stack **stk_a, t_stack **stk_b, int size)
{
	while (ft_rate(*stk_a, 0, size, false) && ft_rate(*stk_b, 0, size, false))
	{
		ft_pairs(*stk_a, *stk_b);
		ft_push_back(**stk_a, **stk_b, size);
	}
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
	}
	ft_shortsort(stk_a);
	ft_returnchunks(stk_a, stk_b, size_start);
	ft_finalsort(stk_a);
}
