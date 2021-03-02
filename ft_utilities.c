/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/02 17:20:49 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void debug_str(const char *s, char *name);
void debug_number(int i, char *name);

void ft_putc(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putc(str[i]);
		++i;
	}
}

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	debug_number(x, "X");
	return (x);
}
