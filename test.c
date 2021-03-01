/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:13:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/01 09:50:24 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define MAXARGS 31

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (*s)
        i++;
    return (i);
}

int ft_test(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0')
    {
        int i = va_arg(args, int);
        printf("%d\n", i);
        fmt++;
    }
    va_end(args);
}

int main()
{
    ft_test("catarina", 8);
    return (0);
}