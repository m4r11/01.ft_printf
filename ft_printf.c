/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/03 18:07:43 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	char *f;
	char *next;
	va_list args;
	va_list args2;
	va_start(args, format);
	va_copy(args2, args);
	size_t i;
	t_converter v;
	char id;
	int j;

	
	i = 0;
	f = format;
	type_f t_f = d;
	while (f[i])
	{
		if (f[i] != '%')
		{
			ft_putc(f[i]);
		}
		else
		{
			i++;
			j = 0;
			while (CONV_S[j++])
			{
				if (CONV_S[j] == f[i])
				{
					next = va_arg(args2, char *);
					ft_putstr(next);
				}
			}
		}
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("i want to say %s to %s because she is %s", "hello", "catarina", "pretty");
	return (0);
}