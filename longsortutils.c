/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/08 18:13:19 by tkeil            ###   ########.fr       */
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
		if (stk->val < pivot || back == false)
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

void	ft_pushbest(t_stack **a, t_stack **b, int d)
{
	t_stack	*stk;

	stk = NULL;
	if (d == 0)
	{
		ft_align(a, b, stk);
		ft_push(a, b, PB);
	}
	else if (d == 1)
	{
		stk = ft_lstfindfastest(*b);
		ft_align(a, b, stk);
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
