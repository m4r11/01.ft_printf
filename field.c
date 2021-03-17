/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:59:38 by user              #+#    #+#             */
/*   Updated: 2021/03/17 19:59:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    put_field(char *dir,va_list args2)
{
        int i;
        int j;
        int len;
        int x;
        char to_convert[500];
        int converted;
        char *temp = (ft_strchr(dir, '%') + 1);
        len = ft_strlen(temp);

            if (temp[0] == '-' && temp[1] == '*')
        field_c_combos(dir, args2); 
        
        i = 0;
        j = 0;
        while (i < (len-1) && j < len)
        {
            to_convert[j] = temp[i];
            i++;
            j++;
        } 
        to_convert[j] = '\0';

        converted = ft_simple_atoi(to_convert);
        x = va_arg(args2, int);
        if (temp[0] == '-')
        {
            //debug_number(converted, "converted");
            ft_putc(x);
            print_x_times(converted - 1, ' ');     
        }
        else 
        {
            //printf("im gere");
            print_x_times(converted , ' ');
            ft_putc(x);
            exit(0);
        }
    return(0);
}

char field_c_combos(char *dir,va_list args2)
{
        int i;
        int j;
        int len;
        int x;
        char to_convert[500];
        int converted;
        char *temp = (ft_strchr(dir, '%') + 1);
        len = ft_strlen(temp);
        
        //debug_str(temp, "temp");
        if (temp[0] == '-' && temp[1] == '*')
        {
           x = va_arg(args2, int);
           converted = va_arg(args2, int);
            if (x >= 0)
            {
                ft_putc(converted);
                print_x_times(x- 1, ' ');
             return(0);
            }
            if (x < 0)
            {
                x *= -1;
                ft_putc(converted);
                print_x_times(x -1, ' ');
            return(0);
            }
       
        }
        return(0);
}


