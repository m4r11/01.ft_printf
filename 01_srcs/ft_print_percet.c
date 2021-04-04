/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:18:24 by user              #+#    #+#             */
/*   Updated: 2021/04/04 22:17:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_percent(char *input, int index, int has_format, va_list args2)
{
    static int count;

    count += 1;
 
    if (input[index] == '%' && count % 2 == 0)
        ft_putc('%');
    return;
}