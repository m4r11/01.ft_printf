/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directives_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:14:27 by user              #+#    #+#             */
/*   Updated: 2021/03/14 16:29:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

char    put_star(char *dir, va_list args2)
{
    int x;
    int i;
    int value;
    i = 0;
    x = va_arg(args2, int);
    value = va_arg(args2, int);
    
    while(dir[i])
    {
        if(dir[i] == 'c')
        {
            ft_putc(value);
            print_x_times(x, ' ');
        }
        i++;
    }
     return(0);
}

char    put_position(char *dir,va_list args2)
{
        ft_putstr("-");
        return(0);
}
char    put_sign(char *dir,va_list args2)
{
        ft_putstr("+");
        return(0);
}
char    put_space(char *dir,va_list args2)
{
        ft_putstr("space");
         return(0);
}
char    put_zeroes(char *dir,va_list args2)
{
        ft_putstr("zeroes");
         return(0);
}
char   put_len(char *dir,va_list args2)
{
        ft_putstr("len");
         return(0);
}
char    put_dec_precision(char *dir,va_list args2)
{
        ft_putstr("presision");
         return(0);
}
char    put_alternate(char *dir,va_list args2)
{
        ft_putstr("0x");
         return(0);
}
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
        
        //debug_str(temp, "temp");
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

/* Don't touch this */