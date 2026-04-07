/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:21:24 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 23:09:36 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] != 0
			&& big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char *)&big[i]);
			++j;
		}	
		++i;
	}	
	return (0);
}
