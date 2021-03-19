/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version16.27ofprintf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:10:36 by user              #+#    #+#             */
/*   Updated: 2021/03/17 11:32:33 by user             ###   ########.fr       */
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
    
    //debug_str(start, "start");
    //debug_number(j, "j");
   if(start[0] == '*')
        return(STAR);
    if(ft_isalpha(start[0]) == 1)
       return(-1);
    if(ft_str_is_numeric(start) != 1)
        return(FIELD);
    if(start[f] == '-')
        return(FIELD);
    if (start[j] == 99)
        return(-1);
    while(start[j])
    {  
        if(ft_str_is_numeric(start) != 1)
            return(FIELD);
        if(ft_isalpha(start[f]) == 1)
            j++;
        //debug_number(j, "j");
        if(start[j]== '%')
            j++;
        //debug_number(j, "j");
        if(start[j] == '*')
            return(STAR);
        if(start[j] == '-')
            return(FIELD);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:10:36 by user              #+#    #+#             */
/*   Updated: 2021/03/16 18:30:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_for_directives(char *flags, char *format, int j)
{
    int i;
    char found;
    char *start = (ft_strchr(format, '%') + 1);
    int argnum;
    int f;
    f = 0;
    argnum = arg_number(format);
    
    //debug_str(start, "start");
    //debug_number(j, "j");
   if(start[0] == '*')
        return(STAR);
    if(ft_isalpha(start[0]) == 1)
       return(-1);
    if(ft_str_is_numeric(start) != 1)
        return(FIELD);
    if(start[f] == '-')
        return(FIELD);
    if (start[j] == 99)
        return(-1);
    while(start[j] && arg_number > 0)
    {  
        if(ft_str_is_numeric(start) != 1)
            return(FIELD);
        if(ft_isalpha(start[f]) == 1)
            j++;
        //debug_number(j, "j");
        if(start[j]== '%')
            j++;
        //debug_number(j, "j");
        if(start[j] == '*')
            return(STAR);
        if(start[j] == '-')
            return(FIELD);
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
