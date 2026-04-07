/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:16:32 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 23:40:29 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	if (i < start)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		if (!arr)
			return (0);
		arr[0] = '\0';
		return (arr);
	}
	if (len > i - start)
		len = i - start;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s + start, len);
	arr[len] = '\0';
	return (arr);
}
