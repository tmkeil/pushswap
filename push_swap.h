/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/31 19:30:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

// typedef struct ss_list
// {
// 	void			*content;
// 	struct ss_list	*next;
// }	t_list;

// push swap
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_rotate(t_list **stack);
void	ft_reverserotate(t_list **stack);

// utils
void	del(void *content);
void	f(void *content);
void	ft_er(void);
void	ft_ptrclr(char **ptr, void (*del)(void*));

#endif
