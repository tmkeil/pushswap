/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:52:41 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/06 16:48:30 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rulecheck(t_stack *lst)
{
	t_stack	*tmp;
	size_t	i;

	i = 0;
	while (lst->next)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->val == tmp->val)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	ft_fill_values(char **str, t_stack **lst)
{
	long	val;
	int		count;
	int		*values;
	int		i;

	count = 0;
	while (str[count])
		count++;
	values = (int *)malloc(sizeof(int) * count);
	if (!values)
		return (0);
	i = 0;
	while (i < count)
	{
		val = ft_atol(str[i]);
		if (val > INT_MAX || val < INT_MIN || val == LONG_MIN)
			return (free(values), 0);
		values[i++] = (int)val;
	}
	i = 0;
	while (i < count)
		ft_lstadd_back_stknode(lst, ft_lstnew_stknode(values[i++]));
	return (free(values), 1);
}

int	ft_preparation(int argc, char **argv, t_stack **stack)
{
	char	**str;
	char	**str2;

	str = NULL;
	str2 = NULL;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		str2 = str;
	}
	else if (argc > 2)
		str = argv + 1;
	if (!str)
		return (ft_ptrclr(str2, del), ft_er(), 0);
	if (!ft_fill_values(str, stack))
		return (ft_ptrclr(str2, del), ft_er(), 0);
	if (!ft_rulecheck(*stack))
		return (ft_lstclear_stknode(stack), ft_ptrclr(str2, del), 0);
	return (ft_ptrclr(str2, del), 1);
}

int	ft_sorted(t_stack *stack)
{
	int	stk_i;
	int	stk_i_next;

	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		stk_i = stack->val;
		stk_i_next = stack->next->val;
		if (stk_i > stk_i_next)
			return (0);
		stack = stack->next;
	}
	return (1);
}
