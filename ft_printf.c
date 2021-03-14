 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/09 18:09:35 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

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
		//&conv_otoa,
		//&print_ptr,
		//&print_n,

	};

int ft_printf(const char *format, ...)
{
   t_struct v;
   t_type type;

   int find_dir;
   int find_flag;
   va_start(args, format);
   va_copy(args2, args);
 
   v.temp = ft_strdup(format);
   int len = ft_strlen(v.temp);

  	 v.i = 0;
 	while (v.temp[v.i])
	{
		if (v.temp[v.i] != '%' && v.temp[v.i] != 'c')
			ft_putc(v.temp[v.i]);
		else 
		{
			//printf("i'm passing here");
			v.i++;
			find_flag = loop_through(CONV_S, v.temp, v.i);
			find_dir = loop_for_directives(DIR_S, v.temp, 0);
		/* 	debug_number(find_dir, "dir");
			debug_number(find_flag, "flag"); */
			if (find_flag > -1)
			{
				has_formating(v.temp, find_dir, args2);
				get_converter[find_flag](find_dir, args2);
				v.i++;
			}	
			if (v.temp[v.i] == ' ')
				ft_putc(v.temp[v.i]);
			v.i++;
		}	
		v.i++;
	}
   va_end(args);
   free(v.temp);
   return (counter(0));
}
