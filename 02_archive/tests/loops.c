/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:27:28 by user              #+#    #+#             */
/*   Updated: 2021/03/18 12:00:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

int    loop_through(char *flags, char *format, int j)
{
    int i;
    char found;
    char *start = ft_strchr(format, '%');

    int f;
    f = 0;
    printf("%s\n", format);
    printf("%s\n", start);
    
    while(start[j] != '%')
    {
        if (start[j] == CONV_S[f])
            j++;
        i = 0;
        while (flags[i] != start[j] && flags[i] < END_DIR)
            i++;
        if (flags[i] == start[j])
        {
            return(i);
                break;
        }
        else 
            i = 0; 
            j++;
            f++;   
    }
    return(-1);
}

int main ()
{
    char *flags = "-+ 0hljz.#123456789";
    char *start = "10%c";
    int found;

    found = loop_through(flags, start, 1);
    printf("%d",found);
}

