/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:26:13 by user              #+#    #+#             */
/*   Updated: 2021/04/16 22:07:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

void	ft_putbnr_intlim(int min_c)
{
	char	*intmin;

	intmin = "2147483648";
	ft_putstr(intmin);
	if (min_c > 0)
		print_x_times(min_c - ft_strlen(intmin), '0');
	return ;
}

void	handles_h(t_h *h, long print, char *hexadecimal)
{
	while (h->quotient != 0)
	{
		if (h->quotient < 0)
			h->quotient = UINT_MAX - ((print * -1) - 1);
		h->remainder = h->quotient % 16;
		if (h->remainder < 10)
			hexadecimal[h->j++] = 48 + h->remainder;
		else
			hexadecimal[h->j++] = 55 + h->remainder;
		h->quotient = h->quotient / 16;
	}
}

void	ft_put_address(long long print)
{
	t_h			h;
	char		hexadecimal[50];

	h.j = 0;
	if (print == (long)LONG_MIN)
	{
		ft_putstr("0x8000000000000000");
		return ;
	}
	if (print == (long)ULONG_MAX)
	{
		ft_putstr("0xffffffffffffffff");
		return ;
	}
	h.quotient = print;
	ft_putc('0');
	ft_putc('x');
	if (h.quotient == 0)
		ft_putc('0');
	handles_h(&h, print, hexadecimal);
	while (h.j-- > 0)
		ft_putc(ft_tolower(hexadecimal[h.j]));
	return ;
}

int	ft_hexlen(long print)
{
	t_h			h;
	char		hexadecimal[20];

	if (print == 0)
		return (3);
	h.j = 0;
	h.quotient = *(long *)&print;
	if (h.quotient == 0)
	{
		hexadecimal[0] = '0';
		h.j += 1;
	}
	else
	{
		hexadecimal[0] = '0';
		hexadecimal[1] = 'x';
		h.j += 2;
	}
	while (h.quotient != 0)
		handles_h(&h, print, hexadecimal);
	return (h.j);
}

int	ft_xlen(long print)
{
	t_h			h;
	char		hexadecimal[20];

	if (print == 0)
		return (3);
	h.j = 0;
	h.quotient = print;
	handles_h(&h, print, hexadecimal);
	return (ft_is_hex(hexadecimal));
}
