/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 19:53:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

// push swap
int	ft_swap(t_list **stack, char *text);
int	ft_push(t_list **stack_from, t_list **stack_to, char *text);
int	ft_rotate(t_list **stack, char *text);
int	ft_reverserotate(t_list **stack, char *text);

// utils
void	del(void *content);
void	f(void *content);
void	ft_er(void);
void	ft_ptrclr(char **ptr, void (*del)(void*));

// utils2
int		ft_rulecheck(char **ptr);
int		ft_preparation(char *ptr, t_list **stack);
int		ft_sorted_asc(t_list *stack);
int		ft_sorted_des(t_list *stack);

// pivots
int		ft_pivot_up(t_list **stack);
int		ft_pivot_down(t_list **stack);

#endif
