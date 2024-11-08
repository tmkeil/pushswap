/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/08 18:15:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shortsort(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*l;

	f = *stack_a;
	s = (*stack_a)->next;
	l = ft_lstlast_stknode(*stack_a);
	if (!stack_a || !*stack_a || !l)
		return ;
	if (ft_lstsize_stknode(stack_a) < 2)
		return ;
	if (f->val > s->val && l->val > f->val)
		ft_swap(stack_a, SA);
	else if (f->val < s->val && f->val > l->val)
		ft_reverserotate(stack_a, RRA);
	else
		ft_rotate(stack_a, RA);
	if (ft_sorted(*stack_a))
		return ;
	else
		return (ft_shortsort(stack_a));
}

void	ft_pushswap(t_stack **stk_a, t_stack **stk_b, int size)
{
	if (!ft_sorted(*stk_a) && ft_lstsize_stknode(stk_a) <= 3)
		return (ft_shortsort(stk_a));
	else if (!ft_sorted(*stk_a) && ft_lstsize_stknode(stk_a) <= 5)
	{
		while (ft_lstsize_stknode(stk_a) > 3)
			ft_push(stk_a, stk_b, PB);
		ft_longsort(stk_a, stk_b, size);
	}
	else if (!ft_sorted(*stk_a))
		return (ft_longsort(stk_a, stk_b, size));
	return ;
}

int	main(int argc, char *argv[])
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_er();
		exit(EXIT_FAILURE);
	}
	if (!ft_preparation(argc, argv, &stack_a))
	{
		ft_er();
		exit(EXIT_FAILURE);
	}
	size = ft_lstsize_stknode(&stack_a);
	ft_pushswap(&stack_a, &stack_b, size);
	ft_lstclear_stknode(&stack_a);
	return (0);
}
