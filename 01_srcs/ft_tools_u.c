/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:58:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/15 21:08:59 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_pad_left_u_aux(int print, int pad, int min_c)
{
	if (min_c < ft_u_intlen(print))
		return (ft_pad_left_len_u(print, pad - ft_u_intlen(print), min_c, ' '));
	else
		return (ft_pad_left_len_u(print, pad - min_c, min_c, ' '));
}

int	ft_pad_left_len_u(int print, int to_pad, int min_c, int c)
{
	print_x_times(to_pad, c);
	ft_putnbr_u_up(print, min_c);
	return (0);
}
