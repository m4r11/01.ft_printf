/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/03 22:52:57 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_printf(char *format, ...)
{
	va_list		args;
	va_list		args2;
	t_struct	v;
	type_f		t_f;
	t_fptr		f_p;

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
				{
					v.next = va_arg(args2, char *);
					ft_putstr(v.next);
				}
			}
		}
		v.i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("i want to say %s to %s because she is %s", "hello", "catarina", "pretty");
	return (0);
}