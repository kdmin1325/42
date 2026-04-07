/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:41:08 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/06 04:12:40 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n--)
	{
		if ((unsigned char )s1[i] != (unsigned char )s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		if (!(unsigned char )s1[i] || !(unsigned char )s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	return (0);
}
