/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:40 by user              #+#    #+#             */
/*   Updated: 2021/03/29 23:05:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_through(char *flags, char *format, int j)
{
    int i;

    if (format[j +1] == 'i')
        return(1);

    while(format[j] != END_DIR)
    {
        //debug_str(&format[j], "format");
        if (format[j] == CONV_S[f])
            j+=1;
        i = 0;
        while (flags[i] != format[j] && flags[i] != '\0')
        {
            //debug_str(&flags[i], "flags");
            i+=1;
        }
   /*      debug_number(i, "I");
        debug_number(j, "J"); */
        if (flags[i] == format[j])
        {
            return(i);
                break;
        }
        else 
            i = 0; 
            j+=1;
      /*       debug_number(i, "i");
            debug_number(j, "j"); */
    }
return(-1);
}