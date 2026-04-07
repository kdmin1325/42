/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:56:22 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 21:56:49 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	sum;
	char	*arr;

	sum = nmemb * size;
	arr = malloc(sum);
	if (!arr)
		return (0);
	ft_memset(arr, 0, sum);
	return (arr);
}
