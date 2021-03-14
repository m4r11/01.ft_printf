/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/14 16:28:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_directives.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

# define NO_FORMAT -1
# define FOUND 
# define LETTER 1

va_list args;
va_list args2;

/*
** enums for modularity: flags, format & size
** 
*/

# define CONV_S "dixXufeEsScgopn"

typedef enum e_ty
{
	d,x,X,u,f,e,E,s,S,c,g,o,p,n,M,END_FLAG
}			t_ty;

# define DIR_S "*-+ 0hljz.#123456789"

typedef enum e_dir 
{
	STAR,
    POSITION,
    SIGN,
    SPACESIGN,
    ZERO,
    SHORT,
    LONG,
    UINTMAX,
    UNSIGNED,
    PRECISION,
    ALTERNATE, 
    FIELD,
    END_DIR,
}			t_dir;


/*
** struct with general use variables 
*/
typedef struct s_struct
{
	char *str;
	char *temp;
	char *next;
	char id;
	int i;
	int j;
	int c;
	int nbr;
	void *kind;
} t_struct;

/*
**  argument type for function, this will be something else
** 	it's juts a placeholder in function 
*/

typedef struct s_type
{
	int nbr;
	void *kind;
	char *str;
} t_type;

/*
**  function * type def for conversion
*/

typedef void (*fptrconv)(int has_format, va_list args2);
typedef char (*fptrdir)(char *dir, va_list args2);

/*
**  conversion func's_declared 
*/

void conv_itoa(int has_format, va_list args2);
void conv_xtoa(int has_format, va_list args2);
void conv_Xtoa(int has_format, va_list args2);
void conv_uitoa(int has_format, va_list args2);
void conv_ftoa(int has_format, va_list args2);
void conv_fetoa(int has_format, va_list args2);
void conv_fetoa(int has_format, va_list args2);
void conv_dtoa(int has_format, va_list args2);
void print_str(int has_format, va_list args2);
void print_c(int has_format, va_list args2);

/*
**  format directives func's_declared 
*/

char    put_star(char *dir, va_list args2);
char   	put_position(char *dir, va_list args2);
char    put_sign(char *dir, va_list args2);
char    put_space(char *dir, va_list args2);
char    put_zeroes(char *dir, va_list args2);
char    put_len(char *dir, va_list args2);
char    put_dec_precision(char *dir, va_list args2);
char    put_alternate(char *dir,va_list args2);
char    put_field(char *dir,va_list args2);

char *has_formating(char *format, int n, va_list args2);
int  get_index(char *s1, char *s2);

/*
** ft_utilities.c
*/

void ft_putc(char c);
void ft_putstr(char *str);
char *ft_strdup(const char *s1);
int ft_intlen_bonus(int);
int counter(int n);
int ft_arglen(va_list TYPE);
int ft_strlen(char *str);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_recursive_power(int nb, int power);
char	*ft_strchr(const char *s, int c);
int		ft_str_is_numeric(char *str);
int			ft_atoi(const char *str);
char	*print_x_times(int n, char c);
int    loop_through(char *flags, char *format, int a);
int	ft_isalpha(int c);
int			ft_simple_atoi(const char *str);

/*
** conv_numbers
*/
void ft_putnbr(int nb);
char *ft_itoa(int n);
bool is_base_valid(char *str);
void ft_putnbr_rebase(int number, int baseleng);
void ft_putnbr_base(int nbr, char *base);
void ft_putfloat(t_type type, va_list args2);

/*
** parse_directives.c
*/
int    loop_for_directives(char *flags, char *format, int j);



/*
** ft_printf.c
*/

int ft_printf(const char *format, ...);

/* 
**debugs
*/

void debug_str(char *s, char *name);
void debug_number(int i, char *name);

#endif
