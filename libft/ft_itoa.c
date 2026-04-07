/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:39:24 by dongminkim        #+#    #+#             */
/*   Updated: 2025/11/28 00:56:54 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	dex_count(int num, int NegativeSum)
{
	int	count_n;
	int	dex;

	dex = num;
	count_n = 0;
	if (num == 0)
		return (2 + NegativeSum);
	while (dex != 0 && ++count_n)
	{
		dex = dex / 10;
	}
	return (count_n + NegativeSum + 1);
}

char	*ft_itoa(int n)
{
	int		isnegative;
	int		length;
	char	*arr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	isnegative = 0;
	if (n < 0)
		isnegative = 1;
	if (isnegative)
		n = n * (-1);
	length = dex_count(n, isnegative);
	arr = malloc(length);
	if (arr == 0)
		return (0);
	arr[0] = '-';
	arr[--length] = 0;
	while (--length && n / 10)
	{
		arr[length] = n % 10 + '0';
		n = n / 10;
	}
	arr[length] = n % 10 + '0';
	return (arr);
}
