/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 19:59:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack, char *text)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_putendl_fd(text, 1);
	return (1);
}

int	ft_push(t_list **stack_from, t_list **stack_to, char *text)
{
	t_list	*tmp;

	if (!stack_from || !*stack_from || !stack_to)
		return (0);
	tmp = (*stack_from);
	if ((*stack_from)->next)
		(*stack_from) = (*stack_from)->next;
	else
		*stack_from = NULL;
	ft_lstadd_front(stack_to, tmp);
	ft_putendl_fd(text, 1);
	return (1);
}

int	ft_rotate(t_list **stack, char *text)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	if (!last)
		return (0);
	last->next = first;
	ft_putendl_fd(text, 1);
	return (1);
}

int	ft_reverserotate(t_list **stack, char *text)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = ft_lstlast(*stack);
	if (!last)
		return (0);
	second_last = *stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_putendl_fd(text, 1);
	return (1);
}
