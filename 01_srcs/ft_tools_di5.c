/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:02:35 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/15 21:05:02 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_putnbr_aux(int print, int to_pad, int min_c)
{
	if (print == INT_MIN)
		print_x_times(to_pad - 10, ' ');
	else
		print_x_times(to_pad - ft_intlen(print), ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_bigprint_min0(int print, int to_pad, int min_c)
{
	print_x_times(to_pad - ft_intlen(print), ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_putnbr_nomin_aux(int print, int to_pad)
{
	if (print < 0)
		print_x_times(to_pad - ft_intlen(print) - 1, '0');
	if (print >= 0)
		print_x_times(to_pad - ft_intlen(print), '0');
	if (print < 0)
		ft_putnbr_up(print, 0);
	if (print >= 0)
		ft_putnbr_up(print, 0);
	return (0);
}

int	ft_pad_left_putnbr_zero_aux(int print, int to_pad, int min_c)
{
	if (ft_intlen(print) > min_c)
	{
		print_x_times(to_pad - ft_intlen(print), ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (print == -1)
		print_x_times(to_pad - min_c - 1, ' ');
	else
		print_x_times(to_pad - min_c, ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

void	ft_aux_putnbr(int print, int min_c, int len)
{
	if (ft_intlen(print) == 1)
		print_x_times(min_c - 1, '0');
	else
		print_x_times(min_c - len, '0');
}
