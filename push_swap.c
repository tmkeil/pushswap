/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 21:06:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	operate_a(t_list **stack_a, t_list **stack_b)
// {
// 	int	f;
// 	int	s;
// 	int	l;
// 	int	val;

// 	if (ft_lstsize(*stack_a) < 2)
// 		return (ft_push(stack_a, stack_b, "pb"));
// 	f = ft_atoi((char *)(*stack_a)->content);
// 	s = ft_atoi((char *)(*stack_a)->next->content);
// 	l = ft_atoi((char *)ft_lstlast(*stack_a)->content);
// 	val = 0;
// 	if (f > s)
// 		val = ft_swap(stack_a, "sa");
// 	else if (l < f)
// 		val = ft_reverserotate(stack_a, "rra");
// 	else if (f < s && l > f)
// 		val = ft_push(stack_a, stack_b, "pb");
// 	else
// 		val = ft_rotate(stack_a, "ra");
// 	return (val);
// }

// int	operate_b(t_list **stack_a, t_list **stack_b)
// {
// 	int	f;
// 	int	s;
// 	int	l;
// 	int	val;

// 	if (ft_lstsize(*stack_b) < 2)
// 		return (ft_push(stack_b, stack_a, "pa"));
// 	f = ft_atoi((char *)(*stack_b)->content);
// 	s = ft_atoi((char *)(*stack_b)->next->content);
// 	l = ft_atoi((char *)ft_lstlast(*stack_b)->content);
// 	val = 0;
// 	if (f < s)
// 		val = ft_swap(stack_b, "sb");
// 	else if (l > f)
// 		val = ft_reverserotate(stack_b, "rrb");
// 	else if (f > s && l < f)
// 		val = ft_push(stack_b, stack_a, "pa");
// 	else
// 		val = ft_rotate(stack_b, "rb");
// 	return (val);
// }

// int	pushswap(t_list **stack_a, t_list **stack_b)
// {
// 	int	pivot_lower;
// 	int	pivot_upper;
// 	int	val;
// 	int	top_value;

// 	pivot_lower = ft_pivot_down(stack_a);
// 	pivot_upper = ft_pivot_up(stack_a);
// 	val = 0;
// 	while (!ft_sorted_asc(*stack_a) && ft_lstsize(*stack_a) > 0)
// 	{
// 		printf("test\n");
// 		top_value = ft_atoi((*stack_a)->content);
// 		if (top_value <= pivot_lower)
// 			val += ft_push(stack_a, stack_b, "pb");
// 		else if (top_value > pivot_lower && top_value <= pivot_upper)
// 		{
// 			val += ft_push(stack_a, stack_b, "pb");
// 			val += ft_rotate(stack_b, "rb");
// 		}
// 		else
// 		{
// 			if (ft_lstsize(*stack_b) > 1)
// 			{
// 				val += ft_rotate(stack_a, "ra");
// 				val += ft_rotate(stack_b, "rb");
// 			}
// 			else
// 				val += ft_rotate(stack_a, "ra");
// 		}
// 	}
// 	while (ft_lstsize(*stack_b) > 0)
// 		val += operate_b(stack_a, stack_b);
// 	while (!ft_sorted_asc(*stack_a))
// 		val += operate_a(stack_a, stack_b);
// 	return (val);
// }

int	operate_a(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	l;
	int	val;

	if (ft_lstsize(*stack_a) < 2)
		return (0);
	f = ft_atoi((char *)(*stack_a)->content);
	s = ft_atoi((char *)(*stack_a)->next->content);
	l = ft_atoi((char *)ft_lstlast(*stack_a)->content);
	val = 0;
	if (f > s)
		val = ft_swap(stack_a, "sa");
	else if (l < f)
		val = ft_reverserotate(stack_a, "rra");
	else if (f < s && l > f)
		val = ft_push(stack_a, stack_b, "pb");
	else
		val = ft_rotate(stack_a, "ra");
	return (val);
}

int	operate_b(t_list **stack_a, t_list **stack_b)
{
	int	f;
	int	s;
	int	l;
	int	val;

	if (ft_lstsize(*stack_b) < 2)
		return (0);
	f = ft_atoi((char *)(*stack_b)->content);
	s = ft_atoi((char *)(*stack_b)->next->content);
	l = ft_atoi((char *)ft_lstlast(*stack_b)->content);
	val = 0;
	if (f < s)
		val = ft_swap(stack_b, "sb");
	else if (l > f)
		val = ft_reverserotate(stack_b, "rrb");
	else if (f > s && l < f)
		val = ft_push(stack_b, stack_a, "pa");
	else
		val = ft_rotate(stack_b, "rb");
	return (val);
}

int	pushswap(t_list **stack_a, t_list **stack_b)
{
	int	val;

	val = 0;
	while (!ft_sorted_asc(*stack_a) || ft_lstsize(*stack_b) != 0)
	{
		val += operate_a(stack_a, stack_b);
		val += operate_b(stack_a, stack_b);
		printf("test\n");
		if (ft_sorted_asc(*stack_a) && ft_sorted_des(*stack_b) && ft_atoi((char *)(*stack_b)->content) < ft_atoi((char *)(*stack_a)->content))
		{
			while (ft_lstsize(*stack_b))
			{
				val += ft_push(stack_b, stack_a, "pa");
			}
		}
	}
	return (val);
}

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
