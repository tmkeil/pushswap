/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 19:18:04 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_movechunk(t_stack **stk_a, t_stack **stk_b, int pivot)
{
	
}

void	ft_longsort(t_stack **stk_a, t_stack **stk_b)
{
	int		pivot;
	int		size_start;
	int		size_curr;

	if (!stk_a || !*stk_a)
		return ;
	size_start = ft_lstsize_stknode(*stk_a);
	size_curr = size_start;
	while (size_curr > 3)
	{
		pivot = ft_convertpivot(ft_pivot(*stk_a), size_start, size_curr);
		ft_movechunk(stk_a, stk_b, pivot);
		size_curr = ft_lstsize_stknode(*stk_a);
	}
	ft_shortsort(stk_a);
	ft_returnchunks(stk_a, stk_b);
	ft_finalsort(stk_a);
}
