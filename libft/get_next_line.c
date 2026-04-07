/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:15:44 by min1325           #+#    #+#             */
/*   Updated: 2026/02/02 07:03:21 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

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

char	*ft_strjo(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*arr;

	if (!s1)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	arr = (char *)malloc(len1 + len2 +1);
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
	free (s1);
	free (s2);
	return (arr);
}

void	b_split(char *save, char *buff, char c)
{
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(buff);
	while (i < s_len)
	{
		if (buff[i++] == c)
		{
			save[j++] = buff[i];
			buff[i++] = 0;
			break ;
		}
	}
	while (i < s_len)
	{
		save[j++] = buff[i++];
	}
	save[j] = '\0';
}

void	save2buff(char *save, char *buff, char c)
{
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(save);
	while (i < s_len)
	{
		buff[i] = save[i];
		if (save[i] == c)
		{
			buff[++i] = 0;
			break ;
		}
		save[i++] = 0;
	}
	buff[i] = 0;
	while (i < s_len)
	{
		save[j++] = save[i++];
	}
	save[j] = 0;
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE];
	char		*buff;
	int			check;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == 0)
		return (0);
	if (save[0])
	{
		if (ft_isset('\n', save))
			return (save2buff(save, buff, '\n'), buff);
		return (save2buff(save, buff, '\n'), ft_strjo(buff, get_next_line(fd)));
	}
	check = gnl_read(fd, buff, BUFFER_SIZE);
	if (check <= 0)
		free (buff);
	if (check <= 0)
		return (0);
	if (check < BUFFER_SIZE)
		return (b_split(save, buff, '\n'), buff);
	if (ft_isset('\n', buff))
		return (b_split(save, buff, '\n'), buff);
	return (b_split(save, buff, '\n'), ft_strjo(buff, get_next_line(fd)));
}

// int	main(void)
// {
//     int	fd;

//     fd = open("./test.txt", O_RDONLY);
// 	char		*buff;
// 	buff = get_next_line(fd);
// 	while (buff )
// 	{
// 		printf("%s", buff);
// 		free(buff);
// 		buff = get_next_line(fd);
// 	}
//     return (0);
// }
