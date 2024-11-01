/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:12:25 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/01 19:28:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>

int	main(void)
{
	int		fd;
	size_t	i;
	int		n;
	int		lower;
	int		upper;
	char	*s;
	bool	exists;
	size_t	count;

	count = 3;
	int numbers[count];
	lower = 1;
	upper = 100;
	i = 0;
	fd = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "nicht offen\n", 12);
		return (1);
	}
	srand(time(0));
	while (i < count)
	{
		do
		{
			n = (rand() % (upper - lower + 1)) + lower;
			exists = false;
			for (size_t j = 0; j < i; j++)
			{
				if (numbers[j] == n)
				{
					exists = true;
					break ;
				}
			}
		} while (exists);
		numbers[i] = n;
		s = ft_itoa(n);
		ft_putstr_fd(s, fd);
		ft_putstr_fd(" ", fd);
		free(s);
		i++;
	}
	close(fd);
}
