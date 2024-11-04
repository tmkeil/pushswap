/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 17:25:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PIVOT_POINT 0.67

// typedef
typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

// operations
void				ft_swap(t_stack **stack, char *text);
void				ft_push(t_stack **from, t_stack **to, char *text);
void				ft_rotate(t_stack **stack, char *text);
void				ft_reverserotate(t_stack **stack, char *text);

// termination utils
void				del(void *content);
void				f(int val);
void				ft_er(void);
long				ft_atol(char *s);
char				*ft_itoa_node(int val);
void				ft_ptrclr(char **ptr, void (*del)(void *));

// validation utils
int					ft_rulecheck(t_stack *lst);
int					ft_preparation(int argc, char **argv, t_stack **stack);
int					ft_sorted(t_stack *stack);

// pivots
int					ft_pivot(t_stack *stack);

// lstutils
t_stack				*ft_lstlast_stknode(t_stack *lst);
t_stack				*ft_lstnew_stknode(int val);
void				ft_lstadd_back_stknode(t_stack **lst, t_stack *node);
void				ft_lstadd_front_stknode(t_stack **lst, t_stack *node);
int					ft_lstsize_stknode(t_stack *lst);
void				ft_lstiter_stknode(t_stack *lst, void (*f)(int));
void				ft_lstclear_stknode(t_stack **lst);

// sorting
void				ft_longsort(t_stack **stk_a, t_stack **stk_b);
#endif
