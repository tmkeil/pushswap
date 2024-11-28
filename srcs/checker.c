/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:11:17 by tobke             #+#    #+#             */
/*   Updated: 2024/11/28 23:31:11 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_operations(t_stack **a, t_stack **b, char *operation)
{
	if (!ft_strncmp(operation, SA, 2))
		return (ft_swap(a, SA), 1);
	else if (!ft_strncmp(operation, SB, 2))
		return (ft_swap(b, SB), 1);
	else if (!ft_strncmp(operation, PA, 2))
		return (ft_push(b, a, PA), 1);
	else if (!ft_strncmp(operation, PB, 2))
		return (ft_push(a, b, PB), 1);
	else if (!ft_strncmp(operation, RA, 2))
		return (ft_rotate(a, RA), 1);
	else if (!ft_strncmp(operation, RB, 2))
		return (ft_rotate(b, RB), 1);
	else if (!ft_strncmp(operation, RRA, 3))
		return (ft_reverserotate(a, RRA), 1);
	else if (!ft_strncmp(operation, RRB, 3))
		return (ft_reverserotate(b, RRB), 1);
	else if (!ft_strncmp(operation, SS, 2))
		return (ft_swap_both(a, b), 1);
	else if (!ft_strncmp(operation, RR, 2))
		return (ft_rotate_both(a, b), 1);
	else if (!ft_strncmp(operation, RRR, 3))
		return (ft_reverserotate_both(a, b), 1);
    else
        return (0);
}

void    ft_checker(t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear_stknode(&a);
	ft_lstclear_stknode(&b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*operation;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_preparation(argc, argv, &a))
		return (ft_er(), 1);
	while (1)
	{
        operation = get_next_line(STDIN_FILENO);
        if (!operation)
            break ;
		if (!ft_operations(&a, &b, operation))
        {
            ft_lstclear_stknode(&a);
            ft_lstclear_stknode(&b);
            return (ft_er(), 1);
        }
		free(operation);
	}
    ft_checker(a, b);
	return (0);
}
