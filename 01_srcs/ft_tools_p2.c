/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:13:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 22:07:46 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

void	ft_put_longlimit(int flag)
{
	char	*longmin;

	if (flag == 3)
		longmin = "FFFFFFFF";
	if (flag == 2)
		longmin = "ffffffff";
	ft_putstr(longmin);
}

int	ft_edge_p_aux(int min_c, long long print)
{
	ft_putstr("0x0");
	if (min_c > 0 && print == 0)
		print_x_times(min_c - 3, '0');
	return (0);
}

int	ft_edge_p(long long print, int min_c)
{
	if (print == 0)
		return (ft_edge_p_aux(min_c, print));
	if (print == 1)
	{
		ft_putstr ("0x1");
		if (min_c > 0 && print == 0)
			print_x_times(min_c - 3, '0');
		return (0);
	}
	if (print == LONG_MIN)
	{
		print_x_times(min_c - (ft_strlen("0x8000000000000000")), '0');
		ft_putstr("0x8000000000000000");
		return (0);
	}
	if (print == UINT_MAX + 1)
	{
		ft_putc(' ');
		return (0);
	}
	return (1);
}

void	ft_put_address_up(long long print, int min_c)
{
	t_h			h;
	char		hexadecimal[100];

	h.j = 0;
	if (ft_edge_p(print, min_c) == 0)
		return ;
	h.quotient = print;
	ft_putc('0');
	ft_putc('x');
	handles_h(&h, print, hexadecimal);
	h.len = ft_is_hex(hexadecimal);
	if (min_c > 0 && print != 0)
	{
		if (ft_intlen(print) == 1)
			print_x_times(min_c - 1, '0');
		else
			print_x_times(min_c - h.len, '0');
	}
	while (h.j-- > 0)
		ft_putc(ft_tolower(hexadecimal[h.j]));
	return ;
}
