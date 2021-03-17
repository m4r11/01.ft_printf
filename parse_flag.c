/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:40 by user              #+#    #+#             */
/*   Updated: 2021/03/17 19:10:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_through(char *flags, char *format, int j)
{
    int i;
    char *start = ft_strchr(format, '%');
    int f;
    f = 0;
	//debug_number(j, "jbefore while");
	
    while(format[j] !='\0')
    {
        if (format[j] == CONV_S[f])
            j++;
        i = 0;
        while (flags[i] != format[j] && flags[i] != '\0')
            i++;
        //debug_number(i, "wehere it stops");
        if (flags[i] == format[j])
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