/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsortutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:14:44 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/05 18:40:39 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_align(t_stack **stk, int size, t_stack *fastest)
{
	int	pos;

	pos = ft_getmoves(*stk, fastest);
	// printf("pos = %i\n", pos);
	if (pos <= size / 2)
	{
		while (pos--)
			ft_rotate(stk, RA);
	}
	else if (pos > size / 2)
	{
		while (pos--)
			ft_reverserotate(stk, RRA);
	}
}

void	ft_pushbest(t_stack **from, t_stack **to, int size, int d)
{
	t_stack	*stk;

	stk = NULL;
	ft_align(from, size, stk);
	// printf("\nstack a nach align\n");
	// ft_lstiter_stknode(*from, f);
	// printf("%i wird in b gepusht\n", (*from)->val);
	if (d == 0)
		ft_push(from, to, PB);
	else if (d == 1)
	{
		stk = ft_lstfindfastest(*from);
		ft_align(from, size, stk);
		ft_align(to, size, stk->pair);
		ft_push(from, to, PA);
	}
}

void	ft_pairs(t_stack *stk_a, t_stack *stk_b)
{
	int		val;
	t_stack	*tmp;

	while (stk_b)
	{
		printf("stack b val = %i\n", stk_b->val);
		tmp = stk_a;
		val = tmp->val;
		while (tmp)
		{
			if (ft_lstextreme(stk_b, 1) == stk_b)
			{
				printf("%i ist das groesste\n", stk_b->val);
				stk_b->pair = ft_lstextreme(stk_a, 0);
				printf("%i bekommt %i\n", tmp->val, tmp->pair->val);
				break ;
			}
			else if (tmp->val < val && tmp->val > stk_b->val)
			{
				stk_b->pair = tmp;
				val = tmp->val;
				printf("%i bekommt %i\n", stk_a->val, stk_a->pair->val);
			}
			tmp = tmp->next;
		}
		stk_b = stk_b->next;
	}
}
