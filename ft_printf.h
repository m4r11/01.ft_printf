/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/03 18:24:01 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdio.h>

/*
** enums for modularity: flags, format & size
*/
# define CONV_S "dixXufeEsSpn"

typedef enum				type_f
{
	d, i, x, X, u, f, e, E, s, S, p, n, END_FLAG
}type_f;

typedef enum				format
{
	left_just, pad_zeros, plus_sign, minus_sign, deviant_op
}format;

typedef	enum				size_mod
{
	h, l, L
}size;

/*
** struct for binding enums to fpointers: get_converter. 
*/

typedef struct		s_converter
{
	char flag;
	void (*fptr)(char *s);
}					t_converter;

/*
** func_pointer defined 
*/
typedef	void		(*operate)(const char *format, ...);
/*
** func's_declared 
*/

void				conv_itoa(const char *format, ...);
void				conv_xtoa(const char *format, ...);
void				conv_uitoa(const char *format, ...);
void				conv_ftoa(const char *format, ...);
void				conv_fetoa(const char *format, ...);
void				conv_dtoa(const char *format, ...);
void				conv_fetoa(const char *format, ...);
void				ft_putstr(char *str);

/*
** variable struct
*/

typedef	struct		s_var
{
	char	*tmp;
	int		i;
	size_t	len;
	int		e_index;
}					t_var;

/*
** ft_utilities.c
*/

void ft_putc(char c);
void ft_putstr(char *str);
int ft_strlen(char *str);


/*
** ft_printf.c
*/
int					ft_printf(char *format, ...);
/*
** debugs
*/
void debug_str(const char *s, char *name);
void debug_number(int i, char *name);

#endif
