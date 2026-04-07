/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:05:21 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/06 04:12:43 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjo(char *s1, char *s2);
void	b_split(char *save, char *buff, char c);
void	save2buff(char *save, char *buff, char c);
char	*get_next_line(int fd);
int		gnl_read(int fd, char *buff, size_t b_size);
#endif
