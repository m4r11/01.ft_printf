/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printbetween%.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:03:14 by user              #+#    #+#             */
/*   Updated: 2021/03/17 17:13:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char ft_putc(char c)
{
	write(1, &c, 1);
    return(0);
}

char print_the_rest(char *input)
{
	int i; 
	i = 2;
	if(input[i] != '%' || input[i] != '\0')
	{
		ft_putc(input[i]);
		i++;
	}
    return(0);
}

int     main()
{
    int r, r2, r3;
    char *s, *s2, *s3;
    s = " %s %s";

    printf("%c\n", print_the_rest(s));
}