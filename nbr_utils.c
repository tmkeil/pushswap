/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/07 21:08:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	size_t	i;
	int		p;
	long	val;
	bool	valid;

	i = 0;
	p = 1;
	val = 0;
	valid = false;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			p = -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		valid = true;
		val = val * 10 + (s[i++] - '0');
	}
	if (!valid || s[i] != '\0')
		return (LONG_MIN);
	return (val * p);
}

static int	ft_len(int val)
{
	int	i;

	i = 0;
	if (val <= 0)
	{
		i++;
		val = -val;
	}
	while (val)
	{
		val /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_node(int val)
{
	int		len;
	char	*s;
	int		sign;

	if (val == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = ft_len(val);
	s = (char *) malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (val < 0)
	{
		sign = 1;
		val = -val;
		s[0] = '-';
	}
	s[len] = '\0';
	while (len - sign > 0)
	{
		s[--len] = val % 10 + '0';
		val /= 10;
	}
	return (s);
}
