/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fiell_u_combos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:28:14 by user              #+#    #+#             */
/*   Updated: 2021/03/29 23:45:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_combos_u(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);              
    if(dv.temp[0] == '-')
    {
        printf("here");
        dv.width = find_width(dv.temp, );
        dv.min_c = ft_atoi(&dir[dv.real + 1]);
        dv.x = va_arg(args2, unsigned int);
        dv.len = ft_intlen(dv.x);
        debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        printf("%u", dv.x);
        debug_number(dv.len, "len");
        return(0);
    }
    return(0);
}