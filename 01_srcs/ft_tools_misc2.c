/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_misc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:49:41 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 22:50:21 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	x_edge_0(int min_c, long print)
{
	ft_putc('0');
	if (min_c > 0 && print == 0)
		print_x_times(min_c - 1, '0');
	return (0);
}

void	printx(t_h *h, char *hexadecimal, int flag)
{
	if (flag == 2)
		ft_putc(ft_tolower(hexadecimal[h->j]));
	if (flag == 3)
		ft_putc(hexadecimal[h->j]);
}
