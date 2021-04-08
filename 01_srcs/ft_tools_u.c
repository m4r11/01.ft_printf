/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:51:46 by user              #+#    #+#             */
/*   Updated: 2021/04/09 00:10:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pad_right_u(int print, int to_pad, int min_c)
{
    if (min_c == 0 && print != 0)
    {
        ft_putnbr_u_up(print, min_c);
        print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
        return (print_x_times((to_pad * -1), ' '));
    if (min_c > 0 && print == 0)
    {
        to_pad *= -1;
        ft_putnbr_u_up(print, min_c);
        if (min_c < ft_u_intlen(print))
            print_x_times(to_pad - ft_u_intlen(print), ' ');
        else
            return (print_x_times(to_pad - min_c, ' '));
    }
    if (min_c < ft_u_intlen(print))
    {
        ft_putnbr_u_up(print, min_c);
        print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
        return (0);
    }
    ft_putnbr_u_up(print, min_c);
    print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int ft_pad_left_len_u(int print, int to_pad, int min_c, int c)
{
    print_x_times(to_pad, c);
    ft_putnbr_u_up(print, min_c);
    return (0);
}

int ft_edge_u(int min_c)
{
    char *uintmax;

    uintmax = "4294967295";
    if (min_c > 0)
        print_x_times(min_c - ft_strlen(uintmax), '0');
    ft_putstr(uintmax);
    return(0);
}