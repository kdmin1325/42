/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:28:22 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/27 20:31:22 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	count_malloc(char *s, char c)
{
	size_t	mal_count;
	size_t	i;

	mal_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			mal_count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (mal_count);
}

size_t	set_raw_malloc(char **set, char *s, char c, size_t mal_count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (s[start] && i < mal_count)
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		set[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (set[i] == 0)
		{
			while (i > 0)
				free(set[--i]);
			return (0);
		}
		start = end;
		i++;
	}
	return (1);
}

void	ft_split_memset(char **dest, char *s, char c, size_t mal_count)
{
	size_t	start;
	size_t	i;
	size_t	j;

	start = 0;
	i = 0;
	while (s[start] && i < mal_count)
	{
		while (s[start] == c && s[start])
			start++;
		j = 0;
		while (s[start] != c && s[start])
			dest[i][j++] = s[start++];
		dest[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	mal_count;
	char	**arr;
	char	*set;
	char	trim_str[2];

	if (s == 0)
		return (0);
	trim_str[0] = c;
	trim_str[1] = '\0';
	set = ft_strtrim(s, trim_str);
	if (set == 0)
		return (0);
	mal_count = count_malloc(set, c);
	arr = (char **)malloc(sizeof(char *) * (mal_count + 1));
	if (arr == 0 || set_raw_malloc(arr, set, c, mal_count) == 0)
	{
		free(arr);
		free(set);
		return (0);
	}
	ft_split_memset(arr, set, c, mal_count);
	arr[mal_count] = 0;
	free(set);
	return (arr);
}
