/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:52:41 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/31 21:14:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rulecheck(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		if (!ft_atoi(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_preparation(char **ptr, t_list **stack)
{
	t_list	*tmp;
	char	**str;
	size_t	i;

	str = ft_split(ptr[1], ' ');
	if (!str)
		return (0);
	if (!ft_rulecheck(str))
		return (ft_ptrclr(str, del), ft_er(), 0);
	i = 0;
	*stack = ft_lstnew(ft_strdup(str[i++]));
	if (!stack || !*stack)
		return (ft_ptrclr(str, del), 0);
	while (str[i])
	{
		tmp = ft_lstnew((void *)ft_strdup(str[i]));
		if (!tmp)
			return (ft_ptrclr(str, del), ft_lstclear(stack, del), 0);
		ft_lstadd_front(stack, tmp);
		i++;
	}
	return (ft_ptrclr(str, del), 1);
}

int	ft_sorted(t_list *stack)
{
	int	stk_i;
	int	stk_i_next;

	if (!stack || !stack->next)
		return (1);
	while (stack)
	{
		if (stack->next)
		{
			stk_i = ft_atoi((char *)stack->content);
			stk_i_next = ft_atoi((char *)stack->next->next);
			if (stk_i > stk_i_next)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}
