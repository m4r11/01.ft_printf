/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/03 09:31:29 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    (*get_converter(t_converter *arr, char c)) (char *s)
{
    int i; 

    i = 0;
    while(arr[i].flag < END_FLAG)
    {
        if (arr[i].flag == c)
             return (arr[i].fptr);
        i++;
    }
    return (NULL);
}