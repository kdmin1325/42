/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 03:37:01 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/07 20:59:32 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr_fd(int n, int fd)
{
	int	mod;
	int	num;

	num = 0;
	if (n == -2147483648)
	{
		num += write(fd, "-2147483648", 11);
		return (num);
	}
	else if (n < 0)
	{
		n = -1 * n;
		num += write(fd, "-", 1);
	}
	mod = n % 10;
	if (n >= 10)
		num += ft_printf_putnbr_fd((n / 10), fd);
	mod += 48;
	num += write(fd, &mod, 1);
	return (num);
}

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	unsigned int	mod;
	int				num;

	num = 0;
	mod = n % 10;
	if (n >= 10)
		num += ft_unsigned_putnbr_fd((n / 10), fd);
	mod += 48;
	num += write(fd, &mod, 1);
	return (num);
}

int	ft_printf_putstr_fd(char *s, int fd)
{
	int		i;
	char	*arr;

	i = 0;
	arr = "(null)";
	if (s == 0)
	{
		i += write (fd, arr, 6);
		return (i);
	}
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_int2char(int c)
{
	char	int2char;

	int2char = (char)c;
	return (write (1, &int2char, 1));
}

int	_dex2hex(unsigned long long c, int flag)
{
	unsigned long long	mod;
	unsigned long long	r;
	int					num;

	num = 0;
	r = c / 16;
	mod = c % 16;
	if (r)
		num = _dex2hex (r, flag);
	mod += ((mod >= 10) * 55);
	mod += ((mod < 10) * '0');
	mod += ((flag == 'x' && (mod >= 65)) * 32);
	num += write(1, &mod, 1);
	return (num);
}
