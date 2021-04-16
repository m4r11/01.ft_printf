/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zconvs1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:03 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 22:48:01 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb <= INT_MAX && nb >= INT_MIN)
	{
		if (nb == INT_MIN)
		{
			ft_putc('-');
			ft_putc('2');
			ft_putnbr(147483648);
		}
		else if (nb < 0)
		{
			ft_putc('-');
			ft_putnbr(-nb);
		}
		else if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putc(nb + '0');
	}
	return ;
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb <= UINT_MAX)
	{
		if (nb == UINT_MAX)
		{
			ft_putc('4');
			ft_putc('2');
			ft_putnbr(94967295);
			return ;
		}
		else if (nb < 0)
		{
			ft_putc('-');
			ft_putnbr_u(-nb);
		}
		else if (nb > 9)
		{
			ft_putnbr_u(nb / 10);
			ft_putnbr_u(nb % 10);
		}
		else
			ft_putc(nb + '0');
	}
	return ;
}

void	ft_putnbr_u_up(unsigned int nb, int min_c)
{
	char	*uintmax;

	if (nb < 0)
		nb = UINT_MAX;
	if (nb <= UINT_MAX)
	{
		if (nb == UINT_MAX)
		{
			uintmax = "4294967295";
			if (min_c > 0)
				print_x_times(min_c - ft_strlen(uintmax), '0');
			ft_putstr(uintmax);
			return ;
		}
		print_x_times(min_c - ft_u_intlen(nb), '0');
		if (nb > 9)
		{
			ft_putnbr_u(nb / 10);
			ft_putnbr_u(nb % 10);
		}
		else
			ft_putc(nb + '0');
	}
	return ;
}

void	ft_put_x(long print, int flag)
{
	t_h			h;
	char		hexadecimal[100];

	h.j = 0;
	if (print == (long)LONG_MIN || print == (long)ULONG_MAX)
	{
		ft_put_longlimit(flag);
		return ;
	}
	if (print == 0)
		ft_putc('0');
	h.quotient = print;
	handles_h(&h, print, hexadecimal);
	while (h.j-- > 0)
	{
		if (flag == 3)
			ft_putc(hexadecimal[h.j]);
		if (flag == 2)
			ft_putc(ft_tolower(hexadecimal[h.j]));
	}
	return ;
}

void	ft_put_x_up(long print, int min_c, int flag)
{
	t_h			h;
	char		hexadecimal[20];

	h.j = 0;
	if (print == (long)ULONG_MAX || print == (long)LONG_MIN)
	{
		edge_x(flag, min_c);
		return ;
	}
	if (print == 0)
	{
		x_edge_0(min_c, print);
		return ;
	}
	h.quotient = print;
	handles_h(&h, print, hexadecimal);
	h.len = ft_is_hex(hexadecimal);
	if (min_c > 0 && print != 0)
		x_zero(min_c, print);
	while (h.j-- > 0)
		printx(&h, hexadecimal, flag);
	return ;
}
