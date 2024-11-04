/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/04 13:20:11 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_short(t_stack **stack_a, t_stack **stack_b)
{
	int	f;
	int	s;
	int	l;

	if (ft_lstsize(*stack_a) < 2)
		return (0);
	f = (*stack_a)->val;
	s = (*stack_a)->next->val;
	l = ft_lstlast_stknode(*stack_a)->val;
	if (f > s && l > f)
		return (ft_swap(stack_a, "sa"));
	else if (f < s && f > l)
		return (ft_reverserotate(stack_a, "rra"));
	else if (f < s && f < l)
		return (ft_push(stack_a, stack_b, "pb"));
	else if (f > s && f > l)
		return (ft_rotate(stack_a, "ra"));
	return (0);
}

// int	pushswap(t_list **stack_a, t_list **stack_b)
// {
// 	int	val;
// 	int	t;

// 	val = 0;
// 	t = 0;
// 	while (!ft_sorted_asc(*stack_a) || ft_lstsize(*stack_b) != 0)
// 	{
// 		t = operate_a(stack_a, stack_b);
// 		val += t;
// 		while (t && !ft_sorted_asc(*stack_a))
// 		{
// 			t = operate_a(stack_a, stack_b);
// 			val += t;
// 		}
// 		t = operate_b(stack_a, stack_b);
// 		val += t;
// 		while (t && !ft_sorted_des(*stack_b))
// 		{
// 			t = operate_b(stack_a, stack_b);
// 			val += t;
// 		}
// 		if (ft_sorted_asc(*stack_a) && ft_sorted_des(*stack_b) && ft_atoi((char *)(*stack_b)->content) < ft_atoi((char *)(*stack_a)->content))
// 		{
// 			while (ft_lstsize(*stack_b))
// 				val += ft_push(stack_b, stack_a, "pa");
// 		}
// 	}
// 	return (val);
// }

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		fd;
	char	line[250];
	int		val;

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
	ft_lstiter(stack_a, f);
	printf("\n");
	val = pushswap(&stack_a, &stack_b);
	printf("stack a\n");
	ft_lstiter(stack_a, f);
	printf("stack b\n");
	ft_lstiter(stack_b, f);
	close(fd);
	printf("val = %i\n", val);
	return (0);
}
