/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:29:30 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/06 06:18:22 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == 32 || (8 < nptr[i] && nptr[i] < 14))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (47 < nptr[i] && nptr[i] < 58)
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}

double	ft_atod(const char *nptr)
{
	double	num;
	int		i;
	int		sign;
	int		down;

	i = 0;
	down = 10;
	sign = 1;
	num = ft_atoi(nptr);
	while (nptr[i++] != '.')
		sign *= ((nptr[i - 1] == '-') * -2) + 1;
	num = sign * num;
	while (47 < nptr[i] && nptr[i] < 58)
	{
		num += ((double)(nptr[i++] - 48) / down);
		down *= 10;
	}
	return (sign * num);
}
