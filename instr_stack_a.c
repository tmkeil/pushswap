/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:01:46 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/29 22:27:14 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (!stack_from || !*stack_from || !stack_to)
		return ;
	tmp = (*stack_from);
	(*stack_from) = (*stack_from)->next;
	ft_lstadd_front(stack_to, tmp);
}

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

// einfacher
void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;                 // Speichert den aktuellen ersten Knoten
	*stack = first->next;           // Setzt den Kopf der Liste auf das zweite Element
	first->next = NULL;             // Trennt den ursprünglichen ersten Knoten vom Rest der Liste
	last = ft_lstlast(*stack);      // Findet den letzten Knoten in der Liste
	last->next = first;             // Hängt den ursprünglichen ersten Knoten ans Ende der Liste
}

void	ft_reverserotate(t_list **stack)
{
	t_list	*iter;
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	iter = *stack;
	last = ft_lstlast(*stack);
	last->next = *stack;
	while (iter->next->next)
	{
		iter->next = iter;
		iter = iter->next;
	}
	iter->next = NULL;
	*stack = last;
}
