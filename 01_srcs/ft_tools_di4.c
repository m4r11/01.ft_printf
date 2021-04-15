/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:50:51 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/15 21:02:48 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_putnbr_zero2_aux(int print, int to_pad, int min_c)
{
	if (print == INT_MIN)
		print_x_times(to_pad - 10, ' ');
	if (print != INT_MIN)
		print_x_times(to_pad - ft_intlen(print), ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	padr_nomin_print0(int print, int to_pad, int min_c, int zero)
{
	if (zero != -1 && print < 0)
	{
		min_c = to_pad;
		ft_putnbr_up(print, min_c);
		return (0);
	}
	ft_putnbr_up(print, min_c);
	print_x_times((to_pad * -1) - 1, ' ');
	return (0);
}

int	ft_pad_left_no_min_zero(int print, int to_pad, int min_c)
{
	if (print == 0)
		print_x_times(to_pad, '0');
	else
	{
		min_c = to_pad;
		if (print < 0)
			min_c -= 1;
		ft_putnbr_up(print, min_c);
	}
	return (0);
}

int	ft_pad_left_bigger_pad_aux(int print, int to_pad, int min_c)
{
	int	temp;

	temp = min_c;
	min_c = ft_intlen(print);
	print_x_times(to_pad - min_c, ' ');
	ft_putnbr_up(print, min_c * -1);
	return (0);
}

int	ft_pad_left_bigger_pad_aux2(int print, int to_pad, int min_c)
{
	if (min_c < -1 && print != INT_MIN)
		print_x_times(to_pad - ft_intlen(print), ' ');
	if (min_c < -1 && print == INT_MIN)
		print_x_times(to_pad - 10, ' ');
	if (min_c < -1)
		ft_putnbr_up(print, 0);
	else
		ft_putnbr_up(print, min_c * -1);
	return (0);
}
