/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:10:36 by user              #+#    #+#             */
/*   Updated: 2021/03/14 14:48:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_for_directives(char *flags, char *format, int j)
{
    int i;
    char found;
    char *start = (ft_strchr(format, '%') + 1);
    int f;
    f = 0;
    
    if(ft_isalpha(start[0]) == 1)
       return(-1);
    if(ft_str_is_numeric(start) != 1)
        return(FIELD);
    if(start[0] == '-')
        return(FIELD);
    if (start[j] == 99)
        return(-1);
    if(start[j] == 42)
        return(STAR);
    while(start[j])
    {  
        if (start[j] == CONV_S[f])
            return(-1);
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
