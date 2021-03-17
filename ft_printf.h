/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/17 18:39:52 by user             ###   ########.fr       */
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
# include <string.h>

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
	int n;
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

typedef void (*fptrconv)(char *input, int has_format, va_list args2);
typedef char (*fptrdir)(char *dir, va_list args2);

/*
**  conversion func's_declared 
*/

void conv_itoa(char *input, int has_format, va_list args2);
void conv_xtoa(char *input, int has_format, va_list args2);
void conv_Xtoa(char *input, int has_format, va_list args2);
void conv_uitoa(char *input, int has_format, va_list args2);
void conv_ftoa(char *input, int has_format, va_list args2);
void conv_fetoa(char *input, int has_format, va_list args2);
void conv_fetoa(char *input, int has_format, va_list args2);
void conv_dtoa(char *input, int has_format, va_list args2);
void print_str(char *input, int has_format, va_list args2);
void print_c(char *input, int has_format, va_list args2);

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
** field.c
*/

char    put_field(char *dir,va_list args2);
char field_c_combos(char *dir,va_list args2);
char    field_c(char *dir,va_list args2);

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
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strnew(size_t size);
int arg_number(char *to_parse);
int		ft_intstrchr(char *s, int c, int start);
int		ft_putcharfrom(char *s, int start, char *dir, char *flag);
void	print_the_rest(char *input, char c);
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
int	parse(char *to_parse, int i);

/* 
**debugs
*/

void debug_str(char *s, char *name);
void debug_number(int i, char *name);

#endif
