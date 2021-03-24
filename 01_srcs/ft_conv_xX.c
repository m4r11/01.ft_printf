/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/03/24 11:57:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_xtoa(char *input, int has_format, va_list args2)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    quotient = va_arg(args2, int);
    if (quotient == 0)
        ft_putc('0');
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
    return;
}

void conv_Xtoa(char *input, int has_format, va_list args2)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    quotient = va_arg(args2, int);
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- >= 0)
        ft_putc(hexadecimal[j]);
    free(hexadecimal);
    return;
}