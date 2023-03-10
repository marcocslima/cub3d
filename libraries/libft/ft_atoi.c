/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:24:44 by mcesar-d          #+#    #+#             */
/*   Updated: 2023/01/24 23:18:21 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *s)
{
	int	index;
	int	isneg;
	int	result;

	index = 0;
	isneg = 1;
	result = 0;
	if (!*s)
		return (257);
	while (ft_isspace(s[index]) == 1)
		index++;
	if (s[index] == '-' || s[index] == '+')
	{
		if (s[index] == '-')
			isneg = isneg * -1;
		index++;
	}
	while (s[index] >= '0' && s[index] <= '9')
	{
		result = (result * 10) + s[index] - '0';
		index++;
	}
	return (result * isneg);
}
