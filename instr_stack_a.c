/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/29 19:22:47 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = (*stack_a);
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	*stack_a = first->next;
	first->next = NULL;
	while (second->next)
		second = second->next;
	second->next = first;
}

void	ft_rra(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack_a || stack_a->next)
		return ;
	tmp = stack_a;
	last = ft_lstlast(stack_a);
	if (!last)
		return ;
	stack_a->content = last->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->next == NULL)
		{
			stack_a->content = tmp->content;
			return ;
		}
		tmp = stack_a;
		stack_a = stack_a->next;
		stack_a->content = tmp->content;
	}
}
