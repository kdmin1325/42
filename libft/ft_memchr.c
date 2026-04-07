/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:24:18 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 23:08:22 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*arr;

	arr = s;
	while (n--)
	{
		if (*arr == (unsigned char)c)
			return ((void *)arr);
		arr++;
	}
	return (0);
}
