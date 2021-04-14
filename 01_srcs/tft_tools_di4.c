/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tft_tools_di4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:50:51 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/14 22:15:33 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int padr_nomin_print0(int print, int to_pad, int min_c, int zero)
{
	if (zero != -1 && print < 0)
	{
		min_c = to_pad;
		ft_putnbr_up(print, min_c);
		return (0);
	}
	ft_putnbr_up(print, min_c);
	print_x_times((to_pad * -1) - 1, ' ');
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