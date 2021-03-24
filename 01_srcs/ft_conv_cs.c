/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/24 12:10:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str(char *input, int has_format, va_list args2)
{
    char *print;
    if( has_format == -1)
    {
        //debug_str(input, "input")o -4 n e daqui;
        print = va_arg(args2, char *);
        ft_putstr(print);
    }
     else 
        return ;
}

void print_c(char *input, int has_format, va_list args2)
{
    int print;
    if (has_format == -1)
    {
        print = va_arg(args2, int);
        ft_putc(print);
    }
    else 
        return ;
}


