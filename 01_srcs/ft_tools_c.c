/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:27:50 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/08 18:55:23 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_pad_left_printc_after_zero(int print, int to_pad)
{
    print_x_times(to_pad - 1, '0');
    ft_putc(print);
    return(0);
}

int    ft_pad_left_printc_after(int print, int to_pad)
{
    print_x_times(to_pad - 1, ' ');
    ft_putc(print);
    return(0);
}

int    ft_printc_pad_right(int print, int to_pad)
{
    ft_putc(print);
    print_x_times(to_pad - 1, ' ');
    return(0);
}