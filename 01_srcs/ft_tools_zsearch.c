/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zsearch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:43:24 by user              #+#    #+#             */
/*   Updated: 2021/04/16 15:51:50 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	find_first_flag(char *input)
{
	t_search	aux;
	static int	pin;

	aux.percent1 = ft_intstrchr_flag(input, '%', pin);
	aux.percent2 = ft_intstrchr(input, '%', aux.percent1);
	aux.flag1_end = aux.percent2;
	while (input[aux.flag1_end])
	{
		aux.i = 0;
		while (CONV_S[i])
		{
			if (CONV_S[aux.i] == input[aux.flag1_end])
				return (find_flaghelp(aux, input));
			aux.i++;
		}
		aux.flag1_end--;
	}
	pin = aux.percent1;
	return (END);
}

int	find_width_d(char *dir, int start, va_list args2)
{
	int	width;

	if (start == -1)
		return (0);
	width = 0;
	while ((dir[start++] && dir[start] != '.') && dir[start] != '\0')
	{
		if (dir[start] == '0')
			start += 1;
		if (dir[start] == '-' && dir[start + 1] != '*')
		{
			if (dir[start + 1] != '0')
				return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
		}
		if (dir[start] == '*')
			return (ft_help_widthp(dir, start, width, args2));
		if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
			return (ft_get_width_atoi2(dir, start, width));
	}
	return (0);
}

int	find_width(char *dir, int start, va_list args2)
{
	int	width;

	if (start == -1)
		return (0);
	width = 0;
	while (dir[start++] != '.')
	{
		if (dir[start] == '0')
			start += 1;
		if (dir[start] == '-' && dir[start + 1] != '*')
		{
			if (dir[start + 1] != '0')
				return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
		}
		if (dir[start] == '*')
			return (ft_help_width(dir, start, width, args2));
		if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
			return (ft_get_width_atoi2(dir, start, width));
	}
	return (0);
}

int	find_width_c(char *dir, int start, va_list args2)
{
	int	width;

	if (start == -1)
		return (0);
	width = 0;
	while (dir[start++] != '.')
	{
		if (dir[start] == '0')
			start += 1;
		if (dir[start] == '-' && dir[start + 1] != '*')
			return (ft_get_width_atoi(dir, start, width));
		if (dir[start] == '*')
		{
			if ((dir[start - 2] == '%' && dir[start - 1] == '-')
				|| (dir[start - 3] == '%' && dir[start - 2] == '-'))
				return (ft_fetch_width(args2, width));
			else
				return (width = va_arg(args2, int));
		}
		if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
			return (ft_get_width_atoi2(dir, start, width));
	}
	return (0);
}

int	find_width_p(char *dir, int start, va_list args2)
{
	int	width;

	if (start == -1)
		return (0);
	width = 0;
	while (dir[start++] != '.')
	{
		if (dir[start] == '0')
			start += 1;
		if (dir[start] == '-' && dir[start + 1] != '*')
			return (ft_get_width_atoi(dir, start, width));
		if (dir[start] == '*')
		{
			if ((dir[start - 2] == '%' && dir[start - 1] == '-')
				|| (dir[start - 3] == '%' && dir[start - 2] == '-'))
				return (ft_fetch_width(args2, width));
			else
				return (width = va_arg(args2, int));
		}
		if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
			return (width = ft_simple_atoi(&dir[start]));
	}
	return (0);
}
