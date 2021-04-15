/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:55:54 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/15 18:21:34 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_putnbr(int print, int to_pad, int min_c)
{
	if (print < 0 && min_c == 0)
		return (ft_pad_left_putnbr_aux(print, to_pad, min_c));
	if (print > 0 && min_c == 0)
		return (ft_pad_left_bigprint_min0(print, to_pad, min_c));
	if (print == INT_MIN)
	{
		print_x_times(to_pad - 10, ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (print < 0 && min_c > 0 && min_c > ft_intlen(print) && print != INT_MIN)
		print_x_times(to_pad - min_c, ' ');
	if (print > 0 && min_c > ft_intlen(print))
		print_x_times(to_pad - min_c, ' ');
	if (print > 0 && min_c > 0 && min_c < ft_intlen(print))
		print_x_times(to_pad - ft_intlen(print), ' ');
	if (print < 0 && min_c > 0 && min_c < ft_intlen(print))
		print_x_times(to_pad - ft_intlen(print) - 1, ' ');
	if (min_c == -1)
		print_x_times(to_pad - ft_intlen(print), ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_putnbr_min(int print, int to_pad, int min_c)
{
	print_x_times(min_c - to_pad, ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_negpad_aux(int print, int to_pad)
{
	if (print < 0)
		ft_putnbr_up(print, to_pad - 1);
	if (print >= 0)
		ft_putnbr_up(print, to_pad);
	return (0);
}

int	ft_pad_left_putnbr_zero(int print, int to_pad, int min_c)
{
	if (print < 0 && ft_intlen(print) <= min_c)
		to_pad -= 1;
	if (min_c == -1)
		return (ft_pad_left_putnbr_nomin_aux(print, to_pad));
	if (min_c < -1)
		return (ft_pad_left_negpad_aux(print, to_pad));
	if (min_c < ft_intlen(print) && print > 0)
		print_x_times(to_pad - ft_intlen(print), ' ');
	if (min_c < ft_intlen(print) && print < 0)
		return (ft_pad_left_putnbr_zero_aux(print, to_pad, min_c));
	if (min_c > ft_intlen(print))
		return (ft_pad_left_putnbr_zero_aux(print, to_pad, min_c));
	if (min_c == ft_intlen(print))
	{
		if (print == INT_MIN)
			print_x_times(to_pad - 10, ' ');
		if (print != INT_MIN)
			print_x_times(to_pad - min_c, ' ');
	}
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_bigger_pad(int print, int to_pad, int min_c)
{
	if (print < 0)
		return (ft_pad_left_bigger_pad_aux2(print, to_pad, min_c));
	else
	{
		if (min_c < 0)
			return (ft_pad_left_bigger_pad_aux(print, to_pad, min_c));
	}
	if (min_c == 0)
	{
		if (print < 0)
			print_x_times(to_pad - ft_intlen(print) - 1, ' ');
		else
			print_x_times(to_pad - ft_intlen(print), ' ');
	}
	else
		print_x_times(to_pad - min_c, ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}
