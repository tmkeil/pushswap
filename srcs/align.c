/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:37:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/30 16:38:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_getmoves(t_stack **stk)
{
	int		pos;
	int		idx;
	int		smallest;
	t_stack	*tmp;

	if (!stk || !*stk)
		return (0);
	pos = 0;
	idx = 0;
	tmp = *stk;
	smallest = tmp->moves;
	while (tmp->next)
	{
		if (tmp->moves < smallest)
		{
			smallest = tmp->moves;
			idx = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (idx);
}

static int	ft_locatebest(t_stack **stk, t_stack *best)
{
	int		idx;
	t_stack	*tmp;

	if (!stk || !*stk)
		return (0);
	idx = 0;
	tmp = *stk;
	while (tmp->next)
	{
		if (tmp == best)
			return (idx);
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}

static void	ft_both(t_stack **a, t_stack **b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		ft_rotate_both(a, b);
		(*pos_a)--;
		(*pos_b)--;
	}
	while (*pos_a < 0 && *pos_b < 0)
	{
		ft_reverserotate_both(a, b);
		(*pos_a)++;
		(*pos_b)++;
	}
}

static void	ft_single(t_stack **a, t_stack **b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0)
	{
		ft_rotate(a, RA);
		(*pos_a)--;
	}
	while (*pos_b > 0)
	{
		ft_rotate(b, RB);
		(*pos_b)--;
	}
	while (*pos_a < 0)
	{
		ft_reverserotate(a, RRA);
		(*pos_a)++;
	}
	while (*pos_b < 0)
	{
		ft_reverserotate(b, RRB);
		(*pos_b)++;
	}
}

void	ft_align(t_stack **a, t_stack **b, t_stack *best)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	if (!best)
	{
		pos_a = ft_getmoves(a);
		pos_b = ft_getmoves(b);
	}
	else
	{
		pos_a = ft_locatebest(a, best->pair);
		pos_b = ft_locatebest(b, best);
	}
	size_a = ft_lstsize_stknode(a);
	size_b = ft_lstsize_stknode(b);
	if (pos_a > size_a / 2)
		pos_a -= size_a;
	if (pos_b > size_b / 2)
		pos_b -= size_b;
	if ((pos_a > 0 && pos_b > 0) || (pos_a < 0 && pos_b < 0))
		ft_both(a, b, &pos_a, &pos_b);
	ft_single(a, b, &pos_a, &pos_b);
}
