/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:52:37 by user              #+#    #+#             */
/*   Updated: 2021/03/19 18:44:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    star_s(char *dir, va_list args2)
{
    int x;
    int i;
    char *value;
    int argnum;
    int start;
    i = 0;
    x = va_arg(args2, int);
    //debug_number(x, "x");
    value = va_arg(args2, char *);
    //debug_str(value, "val");
    argnum = arg_number(dir);
    //debug_str(dir, "dir");
    start = ft_intstrchr_flag(dir, '%', 0);
    //debug_number(start, "start");

    while(dir[i])
    {
        //debug_number(i, "dir i inside while+");
        if (dir[start+3] == '0')
         {
            print_x_times(x + 1, ' ');
            break;
        }
        if (dir[start+1] == '*' && dir[start+2] == '.')
        {
            /* meter aqui condição p/ test 18 onward */
            print_x_times(x, ' ');
            break;
        }
        if (x >= 10)
        {
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - ft_strlen(value), ' ');
            ft_putstr(value);
            //debug_number(value, "value+");
            break;
        }
        if(x >= 0 && x < 10)
        {
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - 1, ' ');
            ft_putstr(value);
            //debug_number(value, "value+");
            break;
        }
        if (x < 0)
        {
            //debug_number(dir[i], "dir inside while-");
            x *= -1;
            ft_putstr(value);
            print_x_times(x -1, ' ');
            //debug_number(value, "value-");
            break;
        }
        i++;
    }
    return(0);

}

char    put_star(char *dir, va_list args2, int flag)
{
    int x;
    int i;
    int value;
    int argnum;
    i = 0;
        if (flag == 8)
            return(star_s(dir,args2));
    x = va_arg(args2, int);
    value = va_arg(args2, int);
    argnum = arg_number(dir);

    while(dir[i])
    {
        if(dir[i] == 'c' && x >= 0)
        {
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - 1, ' ');
            ft_putc(value);
            //debug_number(value, "value+");
            break;
        }
        if (dir[i] == 'c' && x < 0)
        {
            //debug_number(dir[i], "dir inside while-");
            x *= -1;
            ft_putc(value);
            print_x_times(x -1, ' ');
            //debug_number(value, "value-");
            break;
        }
        /* if (x >= 10)
        {
            CHECK WHAT STAR DOES TO NR, AND INLENBONUS FUNC
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - ft_intlen_bonus(value), ' ');
            ft_putc(value);
            //debug_number(value, "value+");
            break;
        }
         */
        i++;
    }
     return(0); 
}