/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/07 22:59:49 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static fptr get_converter[] =
	{

		&conv_itoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&print_str,
		&print_str,
};

int ft_printf(char *format, ...)
{
	va_list args;
	va_list args2;
	t_struct v;
	type_f t_f;
	t_type type;

	va_start(args, format);
	va_copy(args2, args);

	v.i = 0;
	v.f = format;
	t_f = d;
	while (v.f[v.i])
	{
		if (v.f[v.i] != '%')
			ft_putc(v.f[v.i]);
		else
		{
			v.i++;
			v.j = 0;
			while (CONV_S[v.j++])
			{
				if (CONV_S[v.j] == v.f[v.i])
					get_converter[v.j](type, args2);
			}
		}
		v.i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_putstr("%S FLAG\n");
	ft_printf("FT_PRINTF:HELLO say %s to %s because she is %s \n", "hello", "catarina", "pretty");
	printf("RE_PRINTF:HELLO say %s to %s because she is %s \n", "hello", "catarina", "pretty");
	ft_putstr("%d FLAG\n");
	ft_printf("FT_PRINTF:%i,\n", -7);
	ft_printf("FT_PRINTF:%i %i %i \n", -3, 666, 9);
	ft_putstr("%x FLAG\n");
	ft_printf("FT_PRINTF:%x\n", 255);
	printf("RE_PRINTF:%x\n", 255);
	ft_putstr("%X FLAG\n");
	ft_printf("FT_PRINTF:%X\n", 255);
	printf("RE_PRINTF:%X\n", 255);
	ft_putstr("%u FLAG\n");
	ft_printf("FT_PRINTF:%u\n", 255);
	printf("RE_PRINTF:%u\n", 255);
	ft_putstr("%f FLAG\n");
	ft_printf("FT_PRINTF:%f\n", 2.55);
	printf("RE_PRINTF:%f\n", 2.55);
	ft_putstr("%e FLAG\n");
	ft_printf("FT_PRINTF:%e\n", 2.55);
	printf("RE_PRINTF:%e\n", 2.55);
	return (0);
}