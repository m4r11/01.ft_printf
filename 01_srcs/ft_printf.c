/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/04 22:25:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static fptrconv get_converter[] =
	{
		&conv_itoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_fetoa,
		&print_str,
		&print_str,
		&print_c,
		&conv_fetoa,
		&conv_otoa,
		&print_ptr,
		&print_n,
		&print_percent,
};

int ft_printf(const char *format, ...)
{
	t_struct v;
	t_type type;
	va_start(args, format);
	va_copy(args2, args);
	int argnum;

	v.temp = ft_strdup(format);
	int flag;
	char *midle_print;

	v.i = 0;
	while (v.temp[v.i])
	{
		if (v.temp[v.i] == '%')
		{
			flag = parse(v.temp, v.i);
			while (ft_intstrchr(v.temp, '%', v.i) != -1)
			{
				if (flag == 15)
				{
					while (v.temp[v.i + 1] != '%' && v.i <= ft_strlen(v.temp))
					{
						ft_putc(v.temp[v.i + 1]);
						v.i += 1;
					}
				}
				else
					print_the_middle(v.temp, find_first_flag(v.temp));
				v.i = ft_intstrchr(v.temp, '%', v.i);
				flag = parse(v.temp, v.i);
			}
			//debug_number(v.i, "i");
			if (flag == 15 && v.temp[v.i + 1] != '%' && v.temp[v.i + 1] != '\0')
				ft_putc(v.temp[v.i + 1]);
			v.i = ft_putcharfrom(v.temp, v.i, flag);
			if (v.i == END)
				break;
		}
		else
			ft_putc(v.temp[v.i]);
		v.i++;
	}
	va_end(args);
	free(v.temp);
	return (counter(0));
}

int parse(char *to_parse, int i)
{
	t_dir_variables dv;

	int find_dir;
	int find_flag;
	char *parsed = ft_strchr(to_parse, '%');
	int len = ft_strlen(to_parse);
	static int percent;
	percent = i;
	find_flag = loop_through(CONV_S, to_parse, i);
	find_dir = loop_for_directives(DIR_S, to_parse, i);
	percent = ft_intstrchr_flag(to_parse, '%', percent);
	get_converter[find_flag](to_parse, percent, find_dir, args2);
	return (find_flag);
}

/* 
** string to fetch types
** CONV_S "dixXufeEsScgopn%"
** string to fetch dir
** DIR_S "*-+ 0hljz.#123456789" 
*/