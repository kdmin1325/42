/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:11:54 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 23:09:50 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	arr = (char *)malloc(len1 + len2 + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		arr[j++] = s1[i++];
	i = 0;
	while (i < len2)
		arr[j++] = s2[i++];
	arr[j] = '\0';
	return (arr);
}
