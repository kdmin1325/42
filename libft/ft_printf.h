/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:07:48 by dongkim2          #+#    #+#             */
/*   Updated: 2026/01/31 04:00:25 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <time.h>

int	_dex2hex(unsigned long long c, int flag);
int	ft_int2char(int c);
int	ft_printf_putstr_fd(char *s, int fd);
int	ft_unsigned_putnbr_fd(unsigned int n, int fd);
int	ft_printf_putnbr_fd(int n, int fd);
int	ft_printf(const char *format, ...);
int	_ft_printf(const char *format, va_list ap, int i, int *done);
int	ft_addr(unsigned long long c, int flag);

#endif