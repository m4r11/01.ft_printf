/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:26:13 by user              #+#    #+#             */
/*   Updated: 2021/04/15 21:24:37 by mvaldeta         ###   ########.fr       */
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

void	ft_put_address(long long print)
{
	long	quotient;
	long	remainder;
	char	hexadecimal[50];
	int		j;

	j = 0;
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
	quotient = print;
	ft_putc('0');
	ft_putc('x');
	if (quotient == 0)
		ft_putc('0');
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	while (j-- > 0)
		ft_putc(ft_tolower(hexadecimal[j]));
	return ;
}

int	ft_hexlen(long print)
{
	long	quotient;
	long	remainder;
	char	hexadecimal[20];
	int		j;

	if (print == 0)
		return (3);
	j = 0;
	quotient = *(long *)&print;
	if (quotient == 0)
	{
		hexadecimal[0] = '0';
		j += 1;
	}
	else
	{
		hexadecimal[0] = '0';
		hexadecimal[1] = 'x';
		j += 2;
	}
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	return (j);
}

int	ft_xlen(long print)
{
	long	quotient;
	long	remainder;
	char	hexadecimal[20];
	int		j;

	if (print == 0)
		return (3);
	j = 0;
	quotient = print;
	while (quotient != 0)
	{
		if (quotient < 0)
			quotient = UINT_MAX - ((print * -1) - 1);
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	return (ft_is_hex(hexadecimal));
}

int	ft_is_hex(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (!(((str[i] >= 'A' && str[i] <= 'F')
					|| (str[i] >= '0' && str[i] <= '9'))))
			break ;
		else
			c++;
		i++;
	}
	return (c);
}
