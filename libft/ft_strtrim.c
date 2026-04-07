/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 06:09:07 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 21:43:31 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*arr;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	arr = malloc(sizeof(char) * (end - start + 1));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, s1 + start, end - start + 1);
	return (arr);
}
