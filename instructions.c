/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 13:17:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack, char *text)
{
	t_stack	*first;
	t_stack	*second;

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

int	ft_push(t_stack **from, t_stack **to, char *text)
{
	t_stack	*tmp;

	if (!from || !*from || !to)
		return (0);
	tmp = (*from);
	if ((*from)->next)
		(*from) = (*from)->next;
	else
		*from = NULL;
	ft_lstadd_front(to, tmp);
	ft_putendl_fd(text, 1);
	return (1);
}

int	ft_rotate(t_stack **stack, char *text)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	last = ft_lstlast_stknode(*stack);
	if (!last)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl_fd(text, 1);
	return (1);
}

int	ft_reverserotate(t_stack **stack, char *text)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = ft_lstlast_stknode(*stack);
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
