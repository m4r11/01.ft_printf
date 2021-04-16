/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:40 by user              #+#    #+#             */
/*   Updated: 2021/04/16 22:50:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	loop_through(char *flags, char *format, int j)
{
	int	i;

	if (format[j + 1] == 'i')
		return (1);
	if (format[j + 1] == '%')
		return (15);
	while (format[j] != END_DIR)
	{
		if (format[j] == CONV_S[f])
			j += 1;
		i = 0;
		while (flags[i] != format[j] && flags[i] != '\0')
		{
			i += 1;
		}
		if (flags[i] == format[j])
		{
			return (i);
			break ;
		}
		else
			i = 0;
		j += 1;
	}
	return (-3);
}

int	loop_for_directives(char *format, int j)
{
	char	*start;

	start = (ft_strchr(&format[j], '%') + 1);
	if (start[0] == '*')
		return (STAR);
	if (start[0] == '-')
		return (FIELD);
	if (start[0] == '+')
		return (SIGN);
	if (start[0] == ' ')
		return (SPACESIGN);
	if (start[0] == '0')
		return (ZERO);
	if (start[0] == 'h')
		return (SHORT);
	if (start[0] == 'l')
		return (LONG);
	if (start[0] == '.')
		return (PRECISION);
	if (start[0] == '#')
		return (ALTERNATE);
	if (ft_isdigit(start[0]))
		return (FIELD);
	else
		return (-1);
}

int	find_flaghelp(t_search	aux, char *input)
{
	aux.j = 0;
	while (DIR2_S[aux.j])
	{
		if ((DIR2_S[aux.j] == input[aux.flag1_end - 1])
			|| '%' == input[aux.flag1_end - 1])
			return (aux.flag1_end + 1);
		aux.j++;
	}
	return (0);
}
