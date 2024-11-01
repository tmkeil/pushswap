/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 19:31:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_a(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	l;

	f = ft_atoi((char *)(*stack_a)->content);
	s = ft_atoi((char *)(*stack_a)->next->content);
	l = ft_atoi((char *)ft_lstlast(*stack_a)->content);
	if (f > s)
		ft_swap(stack_a, "sa\n");
	else if (l < f)
		ft_reverserotate(stack_a, "rra\n");
	else if (f < s && l > f)
		ft_push(stack_a, stack_b, "pb\n");
	else
		ft_rotate(stack_a, "ra\n");
}

void	operate_b(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	l;

	if (ft_lstsize(*stack_b) == 1)
	{
		ft_push(stack_b, stack_a, "pa\n");
		return ;
	}
	f = ft_atoi((char *)(*stack_b)->content);
	s = ft_atoi((char *)(*stack_b)->next->content);
	l = ft_atoi((char *)ft_lstlast(*stack_b)->content);
	if (f < s)
		ft_swap(stack_b, "sb\n");
	else if (l > f)
		ft_reverserotate(stack_b, "rrb\n");
	else if (f > s && l < f)
		ft_push(stack_b, stack_a, "pa\n");
	else
		ft_rotate(stack_b, "rb\n");
}

void	pushswap(t_list **stack_a, t_list **stack_b)
{
	int	pivot_lower;
	int	pivot_upper;
	int	top_value;

	pivot_lower = ft_pivot_down(stack_a);
	pivot_upper = ft_pivot_up(stack_a);
	while (!ft_sorted_asc(*stack_a) && ft_lstsize(*stack_a) > 0)
	{
		top_value = ft_atoi((*stack_a)->content);
		if (top_value <= pivot_lower)
			ft_push(stack_a, stack_b, "pb\n");
		else if (top_value > pivot_lower && top_value <= pivot_upper)
		{
			ft_push(stack_a, stack_b, "pb\n");
			ft_rotate(stack_b, "rb\n");
		}
		else
			ft_rotate(stack_a, "ra\n");
	}
	while (ft_lstsize(*stack_b) > 0)
		operate_b(stack_a, stack_b);
	while (!ft_sorted_asc(*stack_a))
		operate_a(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		fd;
	char	line[250];

	stack_b = NULL;
	if (argc != 2)
		return (ft_er(), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
		read(fd, line, 200);
	if (fd == -1)
	{
		if (!ft_preparation(argv[1], &stack_a))
			return (1);
	}
	else
	{
		if (!ft_preparation(line, &stack_a))
			return (1);
	}
	// ft_lstiter(stack_a, f);
	pushswap(&stack_a, &stack_b);
	ft_lstiter(stack_a, f);
	close(fd);
	return (0);
}
