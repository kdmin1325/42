/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_etc_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim2 <dongkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 04:26:45 by dongkim2          #+#    #+#             */
/*   Updated: 2026/04/07 20:58:35 by dongkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fratol.h"

int	ft_color_set(int c, unsigned int flag)
{
	static int	color_data;

	if (flag)
		color_data += ft_change_color(color_data);
	return (c + color_data);
}

int	ft_change_color(int c)
{
	if (c > 10000000)
		return (0);
	return (1000);
}

int	is_pass(double real_num, double imagin_num)
{
	double	q;

	if ((real_num + 1) * (real_num + 1) + imagin_num * imagin_num <= 0.0625)
		return (1);
	q = (real_num - 0.25) * (real_num - 0.25) + imagin_num * imagin_num;
	if (q * (q + (real_num - 0.25)) <= 0.25 * imagin_num * imagin_num)
		return (1);
	return (0);
}
