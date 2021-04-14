/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_di1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:55:54 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/14 22:15:24 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pad_left_putnbr_aux(int print, int to_pad, int min_c)
{
    if (print == INT_MIN)
        print_x_times(to_pad - 10, ' ');
    else
        print_x_times(to_pad - ft_intlen(print), ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_putnbr(int print, int to_pad, int min_c)
{
    if (print < 0 && min_c == 0)
        return(ft_pad_left_putnbr_aux(print, to_pad, min_c));
    if (print > 0 && min_c == 0)
    {
        print_x_times(to_pad - ft_intlen(print), ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (print == INT_MIN)
    {
        print_x_times(to_pad - 10, ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (print < 0 && min_c > 0 && min_c > ft_intlen(print) && print != INT_MIN)
        print_x_times(to_pad - min_c, ' ');
    if (print > 0 && min_c > ft_intlen(print))
        print_x_times(to_pad - min_c, ' ');
    if (print > 0 && min_c > 0 && min_c < ft_intlen(print))
        print_x_times(to_pad - ft_intlen(print), ' ');
    if (print < 0 && min_c > 0 && min_c < ft_intlen(print))
        print_x_times(to_pad - ft_intlen(print) - 1, ' ');
    if (min_c == -1)
        print_x_times(to_pad - ft_intlen(print), ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_putnbr_min(int print, int to_pad, int min_c)
{
    print_x_times(min_c - to_pad, ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_putnbr_zero(int print, int to_pad, int min_c)
{
    if (print < 0 && ft_intlen(print) <= min_c)
        to_pad -= 1;
    if (min_c == -1)
    {
        if (print < 0)
            print_x_times(to_pad - ft_intlen(print) - 1, '0');
        if (print >= 0)
            print_x_times(to_pad - ft_intlen(print), '0');
        if (print < 0)
            ft_putnbr_up(print, 0);
        if (print >= 0)
            ft_putnbr_up(print, 0);
        return (0);
    }
    if (min_c < -1)
    {
        if (print < 0)
            ft_putnbr_up(print, to_pad - 1);
        if (print >= 0)
            ft_putnbr_up(print, to_pad);
        return (0);
    }
    if (min_c < ft_intlen(print) && print > 0)
        print_x_times(to_pad - ft_intlen(print), ' ');
    if (min_c < ft_intlen(print) && print < 0)
    {
        if (print == INT_MIN)
            print_x_times(to_pad - 10, ' ');
        if (print != INT_MIN)
            print_x_times(to_pad - ft_intlen(print), ' ');
    }
    if (min_c > ft_intlen(print))
    {
        if (print == INT_MIN)
            print_x_times(to_pad - min_c, ' ');
        if (print != INT_MIN)
            print_x_times(to_pad - min_c, ' ');
    }
    if (min_c == ft_intlen(print))
    {
        if (print == INT_MIN)
            print_x_times(to_pad - 10, ' ');
        if (print != INT_MIN)
            print_x_times(to_pad - min_c, ' ');
    }
    ft_putnbr_up(print, min_c);
    return (0);
}

int ft_pad_left_bigger_pad(int print, int to_pad, int min_c)
{
    int temp;
    if (print < 0)
    {
        if (min_c < -1 && print != INT_MIN)
            print_x_times(to_pad - ft_intlen(print), ' ');
        if (min_c < -1 && print == INT_MIN)
            print_x_times(to_pad - 10, ' ');
        if (min_c < -1)
            ft_putnbr_up(print, 0);
        else
            ft_putnbr_up(print, min_c * -1);
        return (0);
    }
    else
    {
        if (min_c < 0)
        {
            temp = min_c;
            min_c = ft_intlen(print);
            print_x_times(to_pad - min_c, ' ');
            ft_putnbr_up(print, min_c * -1);
            return (0);
        }
    }
    if (min_c == 0)
    {
        if (print < 0)
            print_x_times(to_pad - ft_intlen(print) - 1, ' ');
        else
            print_x_times(to_pad - ft_intlen(print), ' ');
    }
    else
        print_x_times(to_pad - min_c, ' ');
    ft_putnbr_up(print, min_c);
    return (0);
}


