/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:42:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/30 16:39:44 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PIVOT_POINT 0.66
# define PIVOT_END_POINT 0.66
# define SA "sa"
# define RA "ra"
# define RRA "rra"
# define PB "pb"

# define SB "sb"
# define RB "rb"
# define RRB "rrb"
# define PA "pa"

# define SS "ss"
# define RR "rr"
# define RRR "rrr"

// typedef
typedef struct s_stack
{
	int				val;
	int				moves;
	struct s_stack	*next;
	struct s_stack	*pair;
}					t_stack;

// operations
void				ft_swap(t_stack **stack, char *text);
void				ft_push(t_stack **from, t_stack **to, char *text);
void				ft_rotate(t_stack **stack, char *text);
void				ft_reverserotate(t_stack **stack, char *text);
void				ft_swap_both(t_stack **a, t_stack **b);
void				ft_rotate_both(t_stack **a, t_stack **b);
void				ft_reverserotate_both(t_stack **a, t_stack **b);

// termination utils
void				del(void *content);
void				ft_er(void);
long				ft_atol(char *s);

// numbers utils
char				*ft_itoa_node(int val);
void				ft_ptrclr(char **ptr, void (*del)(void *));

// validation utils
int					ft_rulecheck(t_stack *lst);
int					ft_preparation(int argc, char **argv, t_stack **stack);
int					ft_sorted(t_stack *stack);

// pivots
int					ft_convertpivot(t_stack **stk, int size, int n);

// lstutils
t_stack				*ft_lstlast_stknode(t_stack *lst);
t_stack				*ft_lstnew_stknode(int val);
void				ft_lstadd_back_stknode(t_stack **lst, t_stack *node);
void				ft_lstadd_front_stknode(t_stack **lst, t_stack *node);
int					ft_lstsize_stknode(t_stack **lst);
void				ft_lstclear_stknode(t_stack **lst);
t_stack				*ft_lstfindfastest(t_stack *stk);
t_stack				*ft_lstextreme(t_stack *stk, int hilo);

// sorting
void				ft_shortsort(t_stack **stack_a);
void				ft_longsort(t_stack **stk_a, t_stack **stk_b, int size);
int					ft_rate(t_stack *stk, int pivot, int size, bool back);
void				ft_pairs(t_stack *stk_a, t_stack *stk_b);
void				ft_align(t_stack **a, t_stack **b, t_stack *best);
void				ft_finalsort(t_stack **stk, int size);

#endif
