/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:58:56 by dongkim2          #+#    #+#             */
/*   Updated: 2025/11/29 09:42:54 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -1 * n;
		write(fd, "-", 1);
	}
	mod = n % 10;
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	mod += 48;
	write(fd, &mod, 1);
}
