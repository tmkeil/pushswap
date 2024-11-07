/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:03 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/07 21:07:37 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	f(t_stack *stk)
{
	ft_putendl_fd(ft_itoa_node(stk->val), 1);
}

void	ft_er(void)
{
	write(2, "Error\n", 6);
}

void	ft_ptrclr(char **ptr, void (*del)(void *))
{
	size_t	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			del((void *)ptr[i++]);
		free(ptr);
	}
}
