/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/05 22:16:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shortsort(t_stack **stack_a)
{
	int	f;
	int	s;
	int	l;

	if (ft_lstsize_stknode(*stack_a) < 2)
		return ;
	f = (*stack_a)->val;
	s = (*stack_a)->next->val;
	l = ft_lstlast_stknode(*stack_a)->val;
	if (f > s && l > f)
		ft_swap(stack_a, "sa");
	else if (f < s && f > l)
		ft_reverserotate(stack_a, "rra");
	else
		ft_rotate(stack_a, "ra");
	if (ft_sorted(*stack_a))
		return ;
	else
		return (ft_shortsort(stack_a));
}

void	ft_pushswap(t_stack **stk_a, t_stack **stk_b)
{
	if (!ft_sorted(*stk_a) && ft_lstsize_stknode(*stk_a) <= 3)
		return (ft_shortsort(stk_a));
	else if (!ft_sorted(*stk_a))
		return (ft_longsort(stk_a, stk_b));
	return ;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_er(), 1);
	if (!ft_preparation(argc, argv, &stack_a))
		return (1);
	// printf("unsorted lst a:\n");
	// ft_lstiter_stknode(stack_a, f);
	ft_pushswap(&stack_a, &stack_b);
	printf("\n\nsorted lst a:\n");
	ft_lstiter_stknode(stack_a, f);
	// printf("pivot: %i\n", ft_pivot(stack_a));
	ft_lstclear_stknode(&stack_a);
	return (0);
}
