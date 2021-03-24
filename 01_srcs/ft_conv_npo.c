/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_npo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:00:12 by user              #+#    #+#             */
/*   Updated: 2021/03/24 12:01:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_n(char *input, int has_format, va_list args2)
{
    ft_putc('n');
}

void print_ptr(char *input, int has_format, va_list args2)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;
    long *print;
    print = va_arg(args2, long *);
    
    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    quotient = *(long*)&print;
    if (quotient == 0)
        ft_putc('0');
    ft_putc('0');
    ft_putc('x');
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- >0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
}

void conv_otoa(char *input, int has_format, va_list args2)
{
    ft_putc('8');
return ;
}