/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/14 16:28:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

static  fptrdir get_dir[] =
    {
        &put_star,
        &put_position,
        &put_sign,
		&put_sign,
        &put_zeroes,
        &put_len,
		&put_len,
		&put_len,
		&put_len,
        &put_dec_precision,
        &put_alternate,
        &put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
};

char *has_formating(char *format, int n, va_list args2)
{
 /*    debug_number(n, "n");
    debug_str(format, "format"); */
    if(n == NO_FORMAT)
        return(0);
    else
        get_dir[n](format, args2);  
    return(0);
}