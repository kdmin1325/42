/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:50:31 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/07 21:16:45 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (((47 < c) && (c < 58)));
}

int	ft_strdouble(char *arr)
{
	int	i;
	int	n;
	int	flag;

	n = ft_strlen(arr);
	i = 0;
	flag = 0;
	if (arr[i] == '+' || arr[i] == '-')
		i++;
	while (i < n)
	{
		if (ft_isdigit(arr[i++]) == 0)
		{
			if (arr[i -1] == '.' && flag == 0)
				flag = 1;
			else
				return (0);
		}
	}
	return (1);
}
