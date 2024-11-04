/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 13:16:31 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PIVOT_POINT 0.6

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

// push swap
int						ft_swap(t_stack **stack, char *text);
int						ft_push(t_stack **from, t_stack **to, char *text);
int						ft_rotate(t_stack **stack, char *text);
int						ft_reverserotate(t_stack **stack, char *text);

// utils
void					del(void *content);
void					f(void *content);
void					ft_er(void);
void					ft_ptrclr(char **ptr, void (*del)(void *));

// utils2
int						ft_rulecheck(char **ptr);
int						ft_preparation(char *ptr, t_stack **stack);
int						ft_sorted_asc(t_stack *stack);
int						ft_sorted_des(t_stack *stack);

// pivots
int						ft_pivot(t_stack **stack);

// lstutils
t_stack					*ft_lstlast_stknode(t_stack *lst);
#endif
