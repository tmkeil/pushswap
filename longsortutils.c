/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/05 21:48:53 by tkeil            ###   ########.fr       */
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
		// printf("stack val von %i und pivot von %i\n", stk->val, pivot);
		if (stk->val < pivot || !back)
		{
			// printf("war kleiner\n");
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
	// printf("exists = %i\n", exists);
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
	printf("pos = %i\nsize = %i\n", pos, size);
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

void	ft_pushbest(t_stack **a, t_stack **b, int lenb, int d)
{
	int		lena;
	t_stack	*stk;

	stk = NULL;
	// printf("\nstack a nach align\n");
	// ft_lstiter_stknode(*from, f);
	// printf("%i wird in b gepusht\n", (*from)->val);
	lena = ft_lstsize_stknode(*a);
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
		printf("\n\nstack b nach ausrichtung:\n");
		ft_lstiter_stknode(*b, f);
		printf("stack a nach ausrichtung:\n");
		ft_lstiter_stknode(*a, f);
		printf("Operation:\n");
		ft_push(b, a, PA);
	}
}

void	ft_pairs(t_stack *stk_a, t_stack *stk_b)
{
	int		val;
	int		high;
	t_stack	*tmp;

	high = ft_lstextreme(stk_b, 1)->val;
	while (stk_b)
	{
		tmp = stk_a;
		val = tmp->val;
		while (tmp)
		{
			if (high == stk_b->val)
			{
				stk_b->pair = ft_lstextreme(stk_a, 0);
				// stk_b->moves += stk_b->pair->moves;
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
