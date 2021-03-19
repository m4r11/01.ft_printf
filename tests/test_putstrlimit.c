/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstrlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:21 by user              #+#    #+#             */
/*   Updated: 2021/03/19 18:02:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putc(char c)
{
	write(1, &c, 1);
}

char ft_putstr_limit(char *str, int limit)
{
	int i;

	i = 0;
	while ((str[i]) < str[limit])
	{
		ft_putc(str[i]);
		++i;
	}
	return(0);
}

int     main()
{
    char *s;
    int limit; 

    limit = 2;
    s = "hello";

    ft_putstr_limit(s, limit);
}