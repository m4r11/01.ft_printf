/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:18:24 by user              #+#    #+#             */
/*   Updated: 2021/04/16 22:56:42 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(char *input, int index, int has_format, va_list args2)
{
	int				c;
	static int		count;
	t_dir_variables	var;

	if (has_format == -1)
	{
		if (input[index + 1] == '%')
			ft_putc('%');
		count += 1;
		return (ft_intstrchr(input, '%', index));
	}
	else
	{
		var.to_pad = find_width(input, index, args2);
		var.m = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.has_zero = ft_zerochr(input, index);
		c = '%';
		format_c(c, var.to_pad, var.m, var.has_zero);
		return (ft_intstrchr(input, '%', index));
	}
}
