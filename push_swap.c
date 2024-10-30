/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/30 21:24:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*push_swap(int argc, char *argv[])
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	char	**stack;
// 	int		w;

// 	stack = ft_split(argv[1], ' ');
// 	if (!stack)
// 		return (NULL);
// 	w = 0;
// 	stack_a = ft_lstnew((void *) stack[w++]);
// 	if (!stack_a)
// 		return (NULL);
// 	while (stack[w])
// 		ft_lstadd_back(&stack_a, ft_lstnew(stack[w++]));
// 	ft_lstiter(stack_a, f);
// 	return (stack_a);
// }

void	ft_ptrclr(char **ptr, void (*del)(void*))
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		del((void *) ptr[i]);
		i++;
	}
	free(ptr);
}

int	ft_rulecheck(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		if (!ft_atoi(ptr[i]))
			return (0);
	}
	return (1);
}

void	ft_er(void)
{
	write(1, "Error", 5);
}

int	ft_preparation(char **ptr, t_list **stack)
{
	t_list	*tmp;
	char	**str;
	size_t	i;

	str = ft_split(ptr[1], ' ');
	if (!str)
		return (0);
	if (!ft_rulecheck(str))
		return (ft_ptrclr(str, del), ft_er(), 0);
	i = 0;
	*stack = ft_lstnew(str[i++]);
	if (!stack || !*stack)
		return (ft_ptrclr(str, del), 0);
	while (str[i])
	{
		tmp = ft_lstnew((void *) str[i]);
		if (!tmp)
			return (ft_ptrclr(str, del), ft_lstclear(stack, del), 0);
		ft_lstadd_back(stack, tmp);
	}
	return (ft_ptrclr(str, del), 1);
}

int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc != 2)
		return (ft_er(), 1);
	if (!ft_preparation(argv, &stack_a))
		return (1);
	ft_lstiter(stack_a, f);
	return (0);
}
