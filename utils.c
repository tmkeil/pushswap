/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:47:58 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/30 19:20:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = ft_lstlast(*lst);
// 	last->next = new;
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		(*lst)->next = NULL;
// 		return ;
// 	}
// 	new->next = *lst;
// 	*lst = new;
// }

// size_t	ft_lstsize(t_list *lst)
// {
// 	size_t	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = tmp;
// 	}
// 	free(*lst);
// 	*lst = NULL;
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new;
// 	t_list	*tmp;
// 	void	*t;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	new = NULL;
// 	while (lst)
// 	{
// 		t = (*f)(lst->content);
// 		tmp = ft_lstnew(t);
// 		if (!tmp)
// 		{
// 			(del)(t);
// 			ft_lstclear(&new, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new, tmp);
// 		lst = lst->next;
// 	}
// 	return (new);
// }

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		(*f)(lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *a;
// 	t_list *b;

// 	b = NULL;
// 	a = ft_lstnew("node 1");
// 	ft_lstadd_back(&a, ft_lstnew("node 2"));
// 	ft_lstadd_back(&a, ft_lstnew("node 3"));
// 	ft_lstadd_back(&a, ft_lstnew("node 4"));
// 	// swap testing
// 	ft_lstiter(a, f);
// 	// ft_swap(&a);
// 	// ft_lstiter(a, f);

// 	// pb testing
// 	// printf("vor pb\n");
// 	// ft_lstiter(b, f);
// 	// ft_pb(&a, &b);
// 	// printf("einmal pb\n");
// 	// ft_lstiter(b, f);
// 	// ft_pb(&a, &b);
// 	// printf("einmal pb\n");
// 	// ft_lstiter(b, f);
// 	// ft_pb(&a, &b);
// 	// printf("einmal pb\n");
// 	// ft_pb(&a, &b);
// 	// ft_lstiter(b, f);
// 	// printf("\n");
// 	// ft_lstiter(a, f);

// 	// ra testing
// 	// ft_rotate(&a);
// 	// printf("\n");
// 	// printf("after ra\n");
// 	// ft_lstiter(a, f);
// 	// ft_rotate(&a);
// 	// printf("\n");
// 	// printf("after ra\n");
// 	// ft_lstiter(a, f);

// 	// rra testing
// 	ft_reverserotate(&a);
// 	printf("\n");
// 	printf("after rra\n");
// 	ft_lstiter(a, f);
// 	return (0);
// }
