/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:47:06 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 22:50:16 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	pad_left_aux(char *print, int min_c)
{
	if (min_c > 0)
		ft_putstr_limit(print, min_c);
	else
		ft_putstr(print);
	return (0);
}

int	ft_pad_right_x(t_dir_variables var, int size, int c)
{
	ft_put_x_up(var.q, var.min_c, var.flag);
	print_x_times(size, c);
	return (0);
}

int	ft_is_hex(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (!(((str[i] >= 'A' && str[i] <= 'F')
					|| (str[i] >= '0' && str[i] <= '9'))))
			break ;
		else
			c++;
		i++;
	}
	return (c);
}

int	edge_x(int flag, int min_c)
{
	char		*ulongmax;

	if (flag == 3)
		ulongmax = "FFFFFFFF";
	if (flag == 2)
		ulongmax = "ffffffff";
	if (min_c > 0)
		print_x_times(min_c - (ft_strlen(ulongmax)), '0');
	ft_putstr(ulongmax);
	return (0);
}

int	x_zero(int min_c, long print)
{
	if (ft_intlen(print) == 1)
		print_x_times(min_c - 1, '0');
	else
		print_x_times(min_c - ft_xlen(print), '0');
	return (0);
}
