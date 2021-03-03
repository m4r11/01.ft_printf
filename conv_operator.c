/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/03 22:22:35 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    (*get_converter(t_converter *arr, char c)) (char *s)
{
 
        if (arr[i].flag == c)
             return (arr[i].fptr);
        return (NULL);
}

static t_fptr       *(fptr)= {
    &ft_atoi;
    &ft_uitoa;
}