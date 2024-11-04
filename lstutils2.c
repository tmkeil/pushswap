/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:46:29 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 16:55:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter_stknode(t_stack *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->val);
		lst = lst->next;
	}
}

void	ft_lstdelone_stknode(t_stack *lst)
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
