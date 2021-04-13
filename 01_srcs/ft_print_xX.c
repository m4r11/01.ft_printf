/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/13 21:36:45 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int padright_nominc_q0(t_dir_variables var)
{
	ft_put_x_up(var.q, var.min_c, var.flag);
	print_x_times((var.to_pad * -1) - 1, ' ');
	return (0);
}
int padright_minc_minor(t_dir_variables var)
{
	ft_put_x_up(var.q, var.min_c, var.flag);
	if (ft_intlen(var.q) == 1)
		print_x_times((var.to_pad * -1) - 1, ' ');
	else
		print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
	return (0);
}
int padright_bigminc(t_dir_variables var)
{
	var.to_pad *= -1;
	ft_put_x_up(var.q, var.min_c, var.flag);
	if (var.min_c < ft_xlen(var.q))
		print_x_times(var.to_pad - ft_xlen(var.q), ' ');
	else
		print_x_times(var.to_pad - var.min_c, ' ');
	return (0);
}
int padright_bigminc_q0(t_dir_variables var)
{
	var.to_pad *= -1;
	ft_put_x_up(var.q, var.min_c, var.flag);
	if (var.min_c < ft_intlen(var.q))
		print_x_times(var.to_pad - ft_intlen(var.q), ' ');
	else
		print_x_times(var.to_pad - var.min_c, ' ');
	return (0);
}
int padright_minc0(t_dir_variables var)
{
	ft_put_x_up(var.q, var.min_c, var.flag);
	print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
	return (0);
}
int padleft_zeroq(t_dir_variables var)
{
	print_x_times(var.to_pad - 1, ' ');
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}
int padleft_nominc_0(t_dir_variables var)
{
	if (var.q == 0)
		return (print_x_times((var.to_pad), '0'));
	else
		return (padleft_xlen_x(var, '0'));
}
int padleft_min0_no0(t_dir_variables var)
{
	if (var.q == 0)
		return (print_x_times(var.to_pad, ' '));
	else
		return (padleft_xlen_x(var, ' '));
}
int padleft_lesspad(t_dir_variables var)
{
	if (ft_xlen(var.q) == 1 && var.min_c > 1)
	{
		print_x_times(var.min_c - var.to_pad, ' ');
		ft_put_x_up(var.q, var.min_c, var.flag);
		return (0);
	}
	if (var.q == 0)
	{
		print_x_times(var.to_pad - var.min_c, ' ');
		ft_put_x_up(var.q, var.min_c, var.flag);
		return (0);
	}
	if (var.min_c < ft_xlen(var.q))
		print_x_times(var.to_pad - ft_xlen(var.q), ' ');
	else
		return (padleft_minc_x(var));
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}
int padleft_bigpad(t_dir_variables var)
{
	if (ft_xlen(var.q) == 1 && var.min_c > 1)
		return (padleft_minc_x(var));
	if (var.q == 0)
		return (padleft_minc_x(var));
	if (var.min_c < ft_xlen(var.q))
		print_x_times(var.to_pad - ft_xlen(var.q), ' ');
	else
		print_x_times(var.to_pad - var.min_c, ' ');
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}
int padleft_hasz_x(t_dir_variables var)
{
	if (var.min_c == 0 && var.q == 0)
		return (print_x_times(var.to_pad - ft_intlen(var.q) + 1, ' '));
	if (var.min_c == -1 && var.q != 0)
	{
		if (var.min_c < ft_xlen(var.q))
			print_x_times(var.to_pad - ft_xlen(var.q), '0');
		if (var.min_c > ft_xlen(var.q))
			print_x_times(var.to_pad - var.min_c, '0');
		ft_put_x_up(var.q, var.min_c, var.flag);
		return (0);
	}
	if (var.min_c > 0 && var.q == 0)
		return (padleft_minc_x(var));
	if (var.min_c > 0 && var.q != 0)
	{
		if (var.min_c < ft_xlen(var.q))
			return (padleft_xlen_x(var, ' '));
		if (var.min_c > ft_xlen(var.q))
			return (padleft_minc_x(var));
	}
	return(padleft_xlen_x(var, ' '));
}
int padleft_minc_x(t_dir_variables var)
{
	print_x_times(var.to_pad - var.min_c, ' ');
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}
int padleft_xlen_x(t_dir_variables var, int c)
{
	print_x_times(var.to_pad - ft_xlen(var.q), c);
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}





int padleft_x(t_dir_variables var)
{
	if (var.has_zero == 1)
		return (padleft_hasz_x(var));
	if (var.min_c == 0 && var.has_zero == -3)
		return (padleft_min0_no0(var));
	if (var.min_c == -1 && var.has_zero == 1)
		return (padleft_nominc_0(var));
	if (var.min_c == 0 && var.has_zero == 1)
	{
		if (var.q == 0)
			return (print_x_times((var.to_pad), ' '));
		else
			return (padleft_xlen_x(var, ' '));
	}
	if (var.to_pad > var.min_c && var.min_c > 0)
		return (padleft_bigpad(var));
	if (var.to_pad < var.min_c && var.min_c > 0)
		return (padleft_lesspad(var));
	if (var.to_pad > 0 && var.min_c == -1 && var.q == 0)
		return (padleft_zeroq(var));
	if (var.to_pad > 0 && var.min_c == -1 && var.q != 0)
		return (padleft_xlen_x(var, ' '));
	print_x_times(var.min_c - var.to_pad, ' ');
	ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}
int padright_x(t_dir_variables var)
{
	if (var.min_c == 0 && var.q != 0)
		return (padright_minc0(var));
	if (var.min_c == 0 && var.q == 0)
		return (print_x_times((var.to_pad * -1), ' '));
	if (var.min_c > 0 && var.q == 0)
		return (padright_bigminc_q0(var));
	if (var.min_c > 0 && var.q != 0)
		return (padright_bigminc(var));
	if (var.min_c != -1 && var.min_c < ft_xlen(var.q))
		return (padright_minc_minor(var));
	if (var.to_pad < 0 && var.min_c == -1 && var.q == 0)
		return(padright_nominc_q0(var));
	ft_put_x_up(var.q, var.min_c, var.flag);
	if (ft_intlen(var.q) == 1)
		print_x_times((var.to_pad * -1) - 1, ' ');
	if (ft_intlen(var.q) == 2)
		print_x_times((var.to_pad * -1) - 2, ' ');
	else
		print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
	return (0);
}

int format_x(t_dir_variables var)
{
	if (var.to_pad > 0)
		return (padleft_x(var));
	if (var.to_pad < 0)
		return (padright_x(var));
	if (var.to_pad == 0 && var.min_c == 0 && var.q != 0)
		ft_put_x_up(var.q, var.min_c, var.flag);
	if (var.to_pad == 0 && var.min_c < 0)
	{
		ft_put_x_up(var.q, var.min_c, var.flag);
		return (0);
	}
	if (var.to_pad == 0 && var.min_c > 0)
		ft_put_x_up(var.q, var.min_c, var.flag);
	return (0);
}

int conv_xtoa(char *input, int index, int has_format, va_list args2)
{
	t_dir_variables var;

	var.has_zero = ft_zerochr(input, index);
	var.flag = 2;
	if (has_format == -1)
	{
		var.q = va_arg(args2, unsigned long);
		ft_put_x(var.q, var.flag);
		return (ft_intstrchr_flag(input, 'x', index));
	}
	else
	{
		var.to_pad = find_width(input, index, args2);
		var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.q = va_arg(args2, unsigned long);
		format_x(var);
		return (ft_intstrchr_flag(input, 'x', index));
	}
	return (FAIL);
}

int conv_Xtoa(char *input, int index, int has_format, va_list args2)
{
	t_dir_variables var;

	var.flag = 3;
	var.has_zero = ft_zerochr(input, index);
	if (has_format == -1)
	{
		var.q = va_arg(args2, long);
		ft_put_x(var.q, var.flag);
		return (ft_intstrchr_flag(input, 'X', index));
	}
	else
	{
		var.to_pad = find_width(input, index, args2);
		var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.q = va_arg(args2, int);
		format_x(var);
		return (ft_intstrchr_flag(input, 'X', index));
	}
	return (FAIL);
}
