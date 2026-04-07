/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 23:59:30 by dongkim2          #+#    #+#             */
/*   Updated: 2026/01/31 04:36:17 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addr(unsigned long long c, int flag)
{
	int		num;
	char	*arr;

	num = 0;
	if (c == 0)
	{
		arr = "(nil)";
		num += write(1, arr, 5);
		return (num);
	}
	arr = "0x";
	num += write(1, arr, 2);
	num += _dex2hex (c, flag);
	return (num);
}

int	_ft_printf(const char *format, va_list ap, int i, int *done)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == 's')
				*done += ft_printf_putstr_fd(va_arg(ap, char *), 1);
			else if (format[i] == 'c')
				*done += ft_int2char(va_arg(ap, int));
			else if (format[i] == 'd' || format[i] == 'i')
				*done += ft_printf_putnbr_fd(va_arg(ap, int), 1);
			else if (format[i] == 'x' || format[i] == 'X')
				*done += _dex2hex(va_arg(ap, unsigned int), format[i]);
			else if (format[i] == 'u')
				*done += ft_unsigned_putnbr_fd(va_arg(ap, unsigned int), 1);
			else if (format[i] == 'p')
				*done += ft_addr((unsigned long long)va_arg(ap, void *), 'x');
			else if (format[i] == '%')
				*done += write(1, &format[i], 1);
			i++;
			continue ;
		}
		*done += write(1, &format[i++], 1);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	done = 0;
	va_start (arg, format);
	if (format == 0)
		return (-1);
	_ft_printf (format, arg, 0, &done);
	va_end (arg);
	return (done);
}
