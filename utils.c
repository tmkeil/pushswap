/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:03 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 18:49:04 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	f(void *content)
{
	ft_putendl_fd((char *) content, 1);
}

void	ft_er(void)
{
	write(1, "Error\n", 6);
}

void	ft_ptrclr(char **ptr, void (*del)(void*))
{
	size_t	i;

	i = 0;
	while (ptr[i])
		del((void *) ptr[i++]);
	free(ptr);
}
