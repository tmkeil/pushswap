/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:43:39 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/07 21:48:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both(t_stack **a, t_stack **b)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	ft_putendl_fd(SS, 1);
}

void	ft_rotate_both(t_stack **a, t_stack **b)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	ft_putendl_fd(RR, 1);
}

void	ft_reverserotate_both(t_stack **a, t_stack **b)
{
	ft_reverserotate(a, NULL);
	ft_reverserotate(b, NULL);
	ft_putendl_fd(RRR, 1);
}
