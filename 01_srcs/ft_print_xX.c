/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/04 20:31:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_x(long print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
    {
        if (min_c > to_pad)
            to_pad = min_c;
        if (min_c <= 0 && zero != -1)
        {
            if (print == 0)
                print_x_times(to_pad - ft_intlen(print), '0');
            else
                print_x_times(to_pad - ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 2);
            return (0);
        }
        if (min_c == 0 && zero == -1)
        {

            if (print == 0)
            {
                print_x_times(to_pad, ' ');
                return (0);
            }
            print_x_times(to_pad - ft_xlen(print), ' ');
            ft_put_x_up(print, min_c, 2);
            return (0);
        }
        if (min_c == -1 && zero != -1)
        {
            print_x_times((to_pad)-ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 2);
            return (0);
        }
        if (to_pad > min_c && min_c > 0)
        {
            if (ft_xlen(print) == 1 && min_c > 1)
            {
                print_x_times(to_pad - min_c, ' ');
                ft_put_x_up(print, min_c, 2);
                return (0);
            }
            if(print == 0)
            {
                print_x_times(to_pad -min_c, ' ');
                ft_put_x_up(print, min_c, 2);
                return (0);
            }
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            ft_put_x_up(print, min_c, 2);
            return (0);
        }
        if (to_pad > 0 && min_c == -1 && print == 0)
        {
            print_x_times(to_pad - 1, ' ');
            ft_put_x_up(print, min_c, 2);
            return (0);
        }
        print_x_times(min_c - to_pad, ' ');
        ft_put_x_up(print, min_c, 2);
        return (0);
    }
    if (to_pad < 0)
    {
        if (min_c == 0 && print != 0)
        {
            ft_put_x_up(print, min_c, 2);
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        if (min_c == 0 && print == 0)
        {
            print_x_times((to_pad * -1), ' ');
            return (0);
        }
        if (min_c > 0 && print == 0)
        {
            to_pad *= -1;
            ft_put_x_up(print, min_c, 2);
            if (min_c < ft_intlen(print))
                print_x_times(to_pad - ft_intlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c > 0 && print != 0)
        {
            to_pad *= -1;
            ft_put_x_up(print, min_c, 2);
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c != -1 && min_c < ft_xlen(print))
        {
            ft_put_x_up(print, min_c, 2);
            if (ft_intlen(print) == 1)
                print_x_times((to_pad * -1) - 1, ' ');
            else
                print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        if (to_pad < 0 && min_c == -1 && print == 0)
        {
            ft_put_x_up(print, min_c, 2);
            print_x_times((to_pad * -1) - 1, ' ');
            return (0);
        }
        ft_put_x_up(print, min_c, 2);
        if (ft_intlen(print) == 1)
            print_x_times((to_pad * -1) - 1, ' ');
        if (ft_intlen(print) == 2)
            print_x_times((to_pad * -1) - 2, ' ');
        else
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    if (to_pad == 0 && min_c == 0 && print != 0)
        ft_put_x_up(print, min_c, 2);
    if (to_pad == 0 && min_c > 0)
        ft_put_x_up(print, min_c, 2);
    return (0);
}

void conv_xtoa(char *input, int index, int has_format, va_list args2)
{
    int q;
    int width;
    int min_c;
    int dot = ft_intstrchr(input, '.', index);
    int zero = ft_intstrchr(input, '0', index);
    int flag = 2;
    if (dot != -1 || ((dot += 1) == zero))
        zero = -1;
    if (has_format == -1)
    {
        q = va_arg(args2, long);
        ft_put_x(q);
        return;
    }
    else
    {
        width = find_width(input, index, args2);
        //debug_number(width, "w");
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        //debug_number(min_c, "m");
        q = va_arg(args2, int);
        format_x(q, width, min_c, zero);
        return;
    }
    return;
}

int format_X(long print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
    {
        if (min_c > to_pad)
            to_pad = min_c;
        if (min_c <= 0 && zero != -1)
        {
            if (print == 0)
                print_x_times(to_pad - ft_intlen(print), '0');
            else
                print_x_times(to_pad - ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (min_c == 0 && zero == -1)
        {

            if (print == 0)
            {
                print_x_times(to_pad, ' ');
                return (0);
            }
            print_x_times(to_pad - ft_xlen(print), ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (min_c == -1 && zero != -1)
        {
            print_x_times((to_pad)-ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (to_pad > min_c && min_c > 0)
        {
            if (ft_xlen(print) == 1 && min_c > 1)
            {
                print_x_times(to_pad - min_c, ' ');
                ft_put_x_up(print, min_c, 3);
                return (0);
            }
            if(print == 0)
            {
                print_x_times(to_pad -min_c, ' ');
                ft_put_x_up(print, min_c, 3);
                return (0);
            }
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (to_pad > 0 && min_c == -1 && print == 0)
        {
            print_x_times(to_pad - 1, ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        print_x_times(min_c - to_pad, ' ');
        ft_put_x_up(print, min_c, 3);
        return (0);
    }
    if (to_pad < 0)
    {
        if (min_c == 0 && print != 0)
        {
            ft_put_x_up(print, min_c, 3);
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        if (min_c == 0 && print == 0)
        {
            print_x_times((to_pad * -1), ' ');
            return (0);
        }
        if (min_c > 0 && print == 0)
        {
            to_pad *= -1;
            ft_put_x_up(print, min_c, 3);
            if (min_c < ft_intlen(print))
                print_x_times(to_pad - ft_intlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c > 0 && print != 0)
        {
            to_pad *= -1;
            ft_put_x_up(print, min_c, 3);
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c != -1 && min_c < ft_xlen(print))
        {
            ft_put_x_up(print, min_c, 3);
            if (ft_intlen(print) == 1)
                print_x_times((to_pad * -1) - 1, ' ');
            else
                print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        if (to_pad < 0 && min_c == -1 && print == 0)
        {
            ft_put_x_up(print, min_c, 3);
            print_x_times((to_pad * -1) - 1, ' ');
            return (0);
        }
        ft_put_x_up(print, min_c, 3);
        if (ft_intlen(print) == 1)
            print_x_times((to_pad * -1) - 1, ' ');
        if (ft_intlen(print) == 2)
            print_x_times((to_pad * -1) - 2, ' ');
        else
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    if (to_pad == 0 && min_c == 0 && print != 0)
        ft_put_x_up(print, min_c, 3);
    if (to_pad == 0 && min_c > 0)
        ft_put_x_up(print, min_c, 3);
    return (0);
}


void conv_Xtoa(char *input, int index, int has_format, va_list args2)
{
    long q;
    int width;
    int min_c;
    int dot = ft_intstrchr(input, '.', index);
    int zero = ft_intstrchr(input, '0', index);
    if (dot != -1 || ((dot += 1) == zero))
        zero = -1;
    int flag = 3;
    if (has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_x(q);
        return;
    }
    else
    {
        width = find_width(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        q = va_arg(args2, int);
        format_X(q, width, min_c, zero);
        return;
    }
    return;
}

void ft_put_x_up(long print, int min_c, int flag)
{
    long quotient;
    long remainder;
    char hexadecimal[20];
    char *longmin;
    char *ulongmax;
    int len;
    int j = 0;
    if (print == LONG_MIN)
    {
        if(flag == 3)
            longmin = "FFFFFFFF";
        else
            longmin = "ffffffff";
        print_x_times(min_c - (ft_strlen(longmin)), '0');
        ft_putstr(longmin);
        return;
    }
    if (print == ULONG_MAX)
    {
        if(flag == 3)
            ulongmax = "FFFFFFFF";
        else
            ulongmax = "ffffffff";
        if (min_c > 0)
            print_x_times(min_c - (ft_strlen(ulongmax)), '0');
        ft_putstr(ulongmax);
        return;
    }
    if (print == 0)
    {
        ft_putc('0');
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 1, '0');
        return;
    }
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
        {
            quotient = UINT_MAX - ((print * -1) - 1);
        }
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    len = ft_is_hex(hexadecimal);
    if (min_c > 0 && print != 0)
    {
        if (ft_intlen(print) == 1)
            print_x_times(min_c - 1, '0');
        else
            print_x_times(min_c - ft_xlen(print), '0');
    }
    /*     if(min_c > 0 && print == 0)
    {
        print_x_times(min_c, '0');
        return;
    } */
    //debug_str(hexadecimal, "h");
    while (j-- > 0)
    {
        if (flag == 2)
            ft_putc(ft_tolower(hexadecimal[j]));
        if (flag == 3)
            ft_putc(hexadecimal[j]);
    }
    return;
}

void ft_put_x(long print)
{
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    char *ulongmax;
    int j = 0;
    if (print == LONG_MIN)
    {
        longmin = "ffffffff";
        ft_putstr(longmin);
        return;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "ffffffff";
        ft_putstr(ulongmax);
        return;
    }
    if (print == 0)
        ft_putc('0');
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
        {
            quotient = UINT_MAX - ((print * -1) - 1);
        }
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}
void ft_put_X(long print)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;
    char *longmin;
    char *ulongmax;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    if (print == LONG_MIN)
    {
        longmin = "0x8000000000000000";
        ft_putstr(longmin);
        free(hexadecimal);
        return;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "0xffffffffffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return;
    }
    quotient = print;
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
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
}
