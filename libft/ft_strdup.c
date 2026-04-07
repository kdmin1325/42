/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:32:08 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/28 00:02:30 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	num;
	char	*arr;
	size_t	i;

	i = 0;
	num = ft_strlen(s);
	arr = malloc(num * sizeof(char ) + 1);
	if (arr == 0)
		return (0);
	while (i < num)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
