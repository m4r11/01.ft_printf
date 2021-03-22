/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:01:19 by user              #+#    #+#             */
/*   Updated: 2021/03/21 19:55:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    precision_s(char *dir,va_list args2)
{
    int start;
    int real;
    int x;
    char *print;

    print = va_arg(args2, char *);
    //debug_str(print, "print");
    start = ft_intstrchr_flag(dir, '%', 0);
    real = (ft_intstrchr(dir, '%', start) + 2);
   //ft_putc(dir[real]);
    x = ft_atoi(&dir[real]);
    //debug_number(x, "x");
    //ft_putstr_limit(print, x);
    ft_putstr_limit(print, x);
    //debug_number(real, "real");
    return(0);
}

char    precision_int(char *dir,va_list args2)
{
    int start;
    int real;
    int x;
    int print;

    printf("imhere");
    print = va_arg(args2, int);
    debug_number(print, "print");
    start = ft_intstrchr_flag(dir, '%', 0);
    real = (ft_intstrchr(dir, '%', start) + 2);
   //ft_putc(dir[real]);
    x = ft_atoi(&dir[real]);
    //debug_number(x, "x");
    //ft_putstr_limit(print, x);
    ft_putnbr_limit(print, x);
    //debug_number(real, "real");
    return(0);
}

char    put_dec_precision(char *dir,va_list args2, int flag)
{
    if(flag == 8)
        return(precision_s(dir, args2));
    printf("imhere");
    if (flag == 1)
        return(precision_int(dir, args2));
    ft_putstr("presision");
        return(0);
}