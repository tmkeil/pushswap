/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:25:33 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 16:04:30 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_stknode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew_stknode(int val)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_stknode(t_stack **lst, t_stack *node)
{
	t_stack	*last;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	last = ft_lstlast_stknode(*lst);
	if (!last)
		return ;
	last->next = node;
}

void	ft_lstadd_front_stknode(t_stack **lst, t_stack *node)
{
	if (!lst || !node)
		return ;
	node->next = *lst;
	*lst = node;
}

int	ft_lstsize_stknode(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
