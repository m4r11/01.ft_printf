/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:55:54 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/08 22:04:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pad_left_putnbr(int print, int to_pad, int min_c)
{
    print_x_times(to_pad - ft_intlen(print), ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_putnbr_min(int print, int to_pad, int min_c)
{
    print_x_times(min_c - to_pad, ' ');
    ft_putnbr_up(print, min_c);
    ;
    return (0);
}

int ft_pad_left_putnbr_zero(int print, int to_pad, int min_c)
{
    if (print < 0 && ft_intlen(print) <= min_c)
        to_pad -= 1;
    if (min_c < ft_intlen(print))
        print_x_times(to_pad - ft_intlen(print), ' ');
    if (min_c >= ft_intlen(print))
        print_x_times(to_pad - min_c, ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_bigger_pad(int print, int to_pad, int min_c)
{
    if (print < 0)
        print_x_times(to_pad - min_c - 1, ' ');
    else
        print_x_times(to_pad - min_c, ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_minor_min(int print, int to_pad, int min_c)
{
    if (print == 0)
    {
        print_x_times(to_pad - min_c, ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c < ft_intlen(print))
    {
        if (print < 0 && ft_intlen(print) < min_c)
            to_pad -= 1;
        return (ft_pad_left_putnbr(print, to_pad, min_c));
    }
    if (min_c < ft_intlen(print) && print > 0)
        return (ft_pad_left_putnbr(print, to_pad, min_c));
    else
    {
        if (print < 0)
            print_x_times(to_pad - min_c - 1, ' ');
        else
            print_x_times(to_pad - min_c, ' ');
    }
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_no_min_zero(int print, int to_pad, int min_c)
{
    if (print == 0)
        print_x_times(to_pad, '0');
    else
    {
        min_c = to_pad;
        if (print < 0)
            min_c -= 1;
        ft_putnbr_up(print, min_c);
    }
    return (0);
}

int ft_pad_left_no_min_no_zero(int print, int to_pad, int min_c)
{
    if (print == 0)
    {
        if (to_pad >= 1)
        {
            print_x_times(to_pad - 1, ' ');
            ft_putc('0');
            return (0);
        }
        else
            return (print_x_times(to_pad, ' '));
    }
    return (ft_pad_left_putnbr(print, to_pad, min_c));
}

int ft_pad_right(int print, int to_pad, int min_c)
{
    ft_putnbr_up(print, min_c);
    print_x_times((to_pad * -1) - ft_intlen(print), ' ');
    return (0);
}