/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:03 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/31 19:29:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	f(void *content)
{
	printf("%s\n", (char *)content);
}

void	ft_er(void)
{
	write(1, "Error", 5);
}

void	ft_ptrclr(char **ptr, void (*del)(void*))
{
	size_t	i;

	i = 0;
	while (ptr[i])
		del((void *) ptr[i++]);
	free(ptr);
}
