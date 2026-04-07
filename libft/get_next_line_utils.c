/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:00:16 by dongkim2          #+#    #+#             */
/*   Updated: 2026/02/02 06:58:55 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	gnl_read(int fd, char *buff, size_t b_size)
{
	int	check;

	check = read(fd, buff, b_size);
	buff[check] = 0;
	return (0);
}
