/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:59:53 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 22:23:19 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_big_min(t_dir_variables var)
{
	if (ft_xlen(var.q) == 1 && var.m > 1)
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	if (var.q == 0)
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	if (var.m < ft_xlen(var.q))
		print_x_times(var.to_pad - ft_xlen(var.q), ' ');
	else
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	ft_put_x_up(var.q, var.m, var.flag);
	return (0);
}

int	ft_pad_right_zero_x(t_dir_variables var)
{
	var.to_pad *= -1;
	ft_put_x_up(var.q, var.m, var.flag);
	if (var.m < ft_intlen(var.q))
		return (print_x_times(var.to_pad - ft_intlen(var.q), ' '));
	else
		return (print_x_times(var.to_pad - var.m, ' '));
}

int	ft_pad_right_not_zero_x(t_dir_variables var)
{
	var.to_pad *= -1;
	ft_put_x_up(var.q, var.m, var.flag);
	if (var.m < ft_xlen(var.q))
		return (print_x_times(var.to_pad - ft_xlen(var.q), ' '));
	else
		return (print_x_times(var.to_pad - var.m, ' '));
}

int	ft_pad_right_no_min_x(t_dir_variables var)
{
	ft_put_x_up(var.q, var.m, var.flag);
	if (ft_intlen(var.q) == 1)
		return (print_x_times((var.to_pad * -1) - 1, ' '));
	else
		return (print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' '));
}

int	ft_pad_left_x(t_dir_variables var, int size, int c)
{
	print_x_times(size, c);
	ft_put_x_up(var.q, var.m, var.flag);
	return (0);
}
