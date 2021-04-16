/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:45:41 by user              #+#    #+#             */
/*   Updated: 2021/04/16 22:23:05 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_has_zero_x(t_dir_variables var)
{
	if (var.m == 0 && var.q == 0)
		return (print_x_times(var.to_pad - ft_intlen(var.q) + 1, ' '));
	if (var.m == -1 && var.q != 0)
	{
		if (var.m < ft_xlen(var.q))
			print_x_times(var.to_pad - ft_xlen(var.q), '0');
		if (var.m > ft_xlen(var.q))
			print_x_times(var.to_pad - var.m, '0');
		ft_put_x_up(var.q, var.m, var.flag);
		return (0);
	}
	if (var.m > 0 && var.q == 0)
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	if (var.m > 0 && var.q != 0)
	{
		if (var.m < ft_xlen(var.q))
			return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
		if (var.m > ft_xlen(var.q))
			return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	}
	if (var.q == 0)
		print_x_times(var.to_pad, '0');
	if (var.q != 0)
		return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
	return (0);
}

int	ft_no_minc_zero_x(t_dir_variables var)
{
	if (var.q == 0)
		return (print_x_times(var.to_pad, ' '));
	else
		return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
}

int	ft_no_minc_no_zero_x(t_dir_variables var)
{
	if (var.q == 0)
		return (print_x_times((var.to_pad), ' '));
	else
		return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
}

int	ft_no_minc_one_zero_x(t_dir_variables var)
{
	if (var.q == 0)
		return (print_x_times((var.to_pad), '0'));
	else
		return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), '0'));
}

int	ft_pad_left_big_pad(t_dir_variables var)
{
	if (ft_xlen(var.q) == 1 && var.m > 1)
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	if (var.q == 0)
		return (ft_pad_left_x(var, (var.to_pad - var.m), ' '));
	if (var.m < ft_xlen(var.q))
		return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
	else
		print_x_times(var.to_pad - var.m, ' ');
	ft_put_x_up(var.q, var.m, var.flag);
	return (0);
}
