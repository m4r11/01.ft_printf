/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zsearch2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:27:36 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/16 16:01:53 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int	ft_intstrchr_flag(char *s, int c, int start)
{
	int	i;

	i = start;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return (i);
	return (END);
}

int	ft_intstrchr(char *s, int c, int start)
{
	int	i;

	i = start;
	if (s[start] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return (i);
	return (END);
}

int	ft_zerochr(char *s, int start)
{
	if (s[start + 1] == '0')
		return (1);
	else
		return (END);
}

int	find_precision(char *dir, int start, va_list args2)
{
	int	format;

	if (start == -1)
		return (-1);
	if (dir[start] == '.' && dir[start + 1] != '*')
		return (format = (ft_simple_atoi(&dir[start + 1])));
	if (dir[start] == '*' || dir[start + 1] == '*')
		return (format = va_arg(args2, int));
	return (-1);
}
