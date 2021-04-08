/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_aux_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:39:56 by user              #+#    #+#             */
/*   Updated: 2021/04/08 17:34:18 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_putstr_limit(char *str, int limit)
{
	int i;
	i = 0;
	while (i < limit)
	{
		ft_putc(str[i]);
		i++;
	}
	return(0);
}

/* int		ft_putcharfrom(char *s, int start, char flag)
{
	int i;
	i = start;
    int len = 0;
    while(s[i] != CONV_S[flag])
        i++;
    if (i == (ft_strlen(s)-1))
        return(END);
    return(i);
} */

char	print_x_times(int n, char c)
{
	if (n == 0)
        return(0);
	while (n > 0)
	{
		ft_putc(c);
		n--;
	}
	return(0);
}
