/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:46:29 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/30 16:37:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstdelone_stknode(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear_stknode(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_stknode(*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

t_stack	*ft_lstfindfastest(t_stack *stk)
{
	int		val;
	int		moves;
	t_stack	*fastest;

	if (!stk || !stk->pair)
		return (NULL);
	moves = stk->moves + stk->pair->moves;
	fastest = stk;
	while (stk)
	{
		val = stk->moves + stk->pair->moves;
		if (val < moves)
		{
			moves = val;
			fastest = stk;
		}
		stk = stk->next;
	}
	return (fastest);
}

t_stack	*ft_lstextreme(t_stack *stk, int hilo)
{
	int		val;
	t_stack	*extreme;

	val = stk->val;
	extreme = stk;
	while (stk)
	{
		if (stk->val < val && hilo == 0)
		{
			val = stk->val;
			extreme = stk;
		}
		else if (stk->val > val && hilo == 1)
		{
			val = stk->val;
			extreme = stk;
		}
		stk = stk->next;
	}
	return (extreme);
}
