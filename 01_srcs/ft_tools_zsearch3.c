/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zsearch3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:02:28 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 16:04:43 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_get_width_atoi(char *dir, int start, int width)
{
	if (dir[start + 1] != '0')
		return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
	else
		return (0);
}

int	ft_get_width_atoi2(char *dir, int start, int width)
{
	if (dir[start - 2] == '-')
		return (width = ft_simple_atoi(&dir[start]) * -1);
	else
		return (width = ft_simple_atoi(&dir[start]));
}

int	ft_help_widthp(char *dir, int start, int width, va_list args2)
{
	if (((dir[start - 2] == '%' && dir[start - 1] == '-')
			|| (dir[start - 3] == '%' && dir[start - 2] == '-')
			|| dir[start - 1] == '-'))
	{
		width = va_arg(args2, int);
		if (width > 0)
			return (-1 * width);
		else
			return (width);
	}
	else
		return (width = va_arg(args2, int));
}

int	ft_help_width(char *dir, int start, int width, va_list args2)
{
	if (((dir[start - 2] == '%' && dir[start - 1] == '-')
			|| (dir[start - 3] == '%' && dir[start - 2] == '-')
			|| dir[start - 1] == '-'))
		return (ft_fetch_width(args2, width));
	else
		return (width = va_arg(args2, int));
}
