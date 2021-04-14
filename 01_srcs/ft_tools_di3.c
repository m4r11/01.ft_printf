/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:44:11 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/14 22:02:20 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int padr_nozero_lessprint(int print, int to_pad, int min_c)
{
	if (print == CHAR_MIN || print == CHAR_MAX)
		return(padr_chrminmax2(print, to_pad, min_c));
	if (print == INT_MIN || print == INT_MAX)
	{
		ft_putnbr_up(print, min_c);
		print_x_times((to_pad * -1) - 10, ' ');
		return (0);
	}
	ft_putnbr_up(print, min_c);
	if (min_c > 0 && min_c > ft_intlen(print))
	{
		if (print < 0)
			print_x_times((to_pad * -1) - min_c - 1, ' ');
		return (0);
	}
	else
	{
		if (print < 0 && min_c < ft_intlen(print) && min_c > 0)
			return (print_x_times((to_pad * -1) - (ft_intlen(print)), ' '));
		if (print >= 0 && min_c < ft_intlen(print) && min_c > 0)
			return (print_x_times((to_pad * -1) - (ft_intlen(print)), ' '));
		if (print < 0 && min_c < ft_intlen(print) && min_c == -1)
			return (print_x_times((to_pad * -1) - (ft_intlen(print)), ' '));
		else
			print_x_times((to_pad * -1) - min_c - 1, ' ');
	}
	return (0);
}

int ft_pad_right(int print, int to_pad, int min_c)
{
	ft_putnbr_up(print, min_c);
	if (print < 0 && print != INT_MIN)
		print_x_times((to_pad * -1) - ft_intlen(print), ' ');
	if (print < 0 && print == INT_MIN)
		print_x_times((to_pad * -1) - 10, ' ');
	if (print >= 0)
		print_x_times((to_pad * -1) - ft_intlen(print), ' ');
	return (0);
}

int padr_chrminmax2(int print, int to_pad, int min_c)
{
	ft_putnbr_up(print, min_c);
	if (print < 0 && min_c < ft_intlen(print))
		return (print_x_times((to_pad * -1) - ft_intlen(print), ' '));
	if (print < 0 && min_c == ft_intlen(print))
		return (print_x_times((to_pad * -1) - ft_intlen(print) - 1, ' '));
	if (print < 0 && min_c > ft_intlen(print))
		return (print_x_times((to_pad * -1) - min_c - 1, ' '));
	if (print >= 0)
		return (print_x_times((to_pad * -1) - min_c, ' '));
	return (0);
}
int padr_chrminmax(int print, int to_pad, int min_c)
{
	if (print < 0 && min_c >= ft_intlen(print))
		print_x_times((to_pad * -1) - min_c - 1, ' ');
	if (print < 0 && min_c < ft_intlen(print))
		print_x_times((to_pad * -1) - ft_intlen(print) - 1, ' ');
	if (print >= 0)
		print_x_times((to_pad * -1) - min_c, ' ');
	return (0);
}
int padr_nomin_generic(int print, int to_pad, int min_c)
{
	if (to_pad < 0)
		to_pad *= -1;
	ft_putnbr_up(print, min_c);
	if (print == INT_MIN)
		print_x_times(to_pad - 10, ' ');
	else
		print_x_times(to_pad - ft_intlen(print), ' ');
	return (0);
}