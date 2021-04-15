/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:43:49 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/15 20:28:00 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_no_min_no_zero(int print, int to_pad, int min_c)
{
	if (print == 0)
	{
		if (to_pad >= 1)
		{
			print_x_times(to_pad - 1, ' ');
			ft_putc('0');
			return (0);
		}
		else
			return (print_x_times(to_pad, ' '));
	}
	if (print == INT_MIN || print == INT_MAX)
	{
		print_x_times(to_pad - 10, ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	return (ft_pad_left_putnbr(print, to_pad, min_c));
}

int	ft_pad_left_minor_min_aux2(int print, int to_pad, int min_c)
{
	if (print == INT_MIN)
	{
		if (min_c < 10)
			min_c = 10;
		print_x_times(to_pad - min_c - 1, ' ');
		if (min_c == 10)
			min_c = 0;
		if (min_c > 10)
		{
			ft_putc('-');
			print_x_times(to_pad - min_c - 1, '0');
			ft_putstr("2147483648");
			return (0);
		}
		ft_putnbr_up(print, min_c);
		return (0);
	}
	else
		print_x_times(to_pad - min_c - 1, ' ');
	ft_putnbr_up(print, min_c);
	return (0);
}

int	ft_pad_left_minor_min_aux1(int print, int to_pad, int min_c)
{
	if (print == INT_MIN)
	{
		print_x_times(to_pad - 10, ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (print < 0)
	{
		print_x_times(to_pad - ft_intlen(print), ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (print >= 0)
	{
		print_x_times(to_pad - ft_intlen(print), ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	return (0);
}

int	ft_pad_left_minor_min(int print, int to_pad, int min_c)
{
	if (print == 0)
	{
		print_x_times(to_pad - min_c, ' ');
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (min_c < ft_intlen(print))
		return (ft_pad_left_minor_min_aux1(print, to_pad, min_c));
	if (min_c < ft_intlen(print) && print > 0)
		return (ft_pad_left_putnbr(print, to_pad, min_c));
	else
	{
		if (print < 0)
			return (ft_pad_left_minor_min_aux2(print, to_pad, min_c));
		if (print >= 0)
		{
			print_x_times(to_pad - min_c, ' ');
			ft_putnbr_up(print, min_c);
			return (0);
		}
	}
	ft_putnbr_up(print, min_c);
	return (0);
}

void	ft_putnbr_up(int print, int min_c)
{
	if (print < 0)
	{
		print *= -1;
		ft_putc('-');
	}
	if (print == INT_MIN)
	{
		ft_putbnr_intlim(min_c);
		return ;
	}
	if (min_c > 0 && print == 0)
	{
		print_x_times(min_c, '0');
		return ;
	}
	if (min_c > 0 && print != 0)
		ft_aux_putnbr(print, min_c, ft_intlen(print));
	if (print > 9)
	{
		ft_putnbr(print / 10);
		ft_putnbr(print % 10);
	}
	else
		ft_putc(print + '0');
	return ;
}
