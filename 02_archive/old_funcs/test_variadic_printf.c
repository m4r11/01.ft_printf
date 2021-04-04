/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_variadic_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:02:47 by user              #+#    #+#             */
/*   Updated: 2021/04/04 22:07:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

void ft_putc(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    t_struct v;
    int i;

    i = 0;
    while ((str[i]) != '\0')
    {
        ft_putc(str[i]);
        ++i;
        //counter(1);
    }
}

char print_x_times(int n, char c)
{
    if (n == 0)
        return (0);
    if (n < 0)
        n *= -1;
    while (n > 0)
    {
        ft_putc(c);
        n--;
    }
    return (0);
}

int ft_strlen(char *str)
{
    if (!str)
        return (0);
    int x;
    x = 0;
    while (str[x] != '\0')
    {
        ++x;
    }
    return (x);
}

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c - ('A' - 'a'));
    return (c);
}

int ft_xlen(long print)
{
    long decimal;
    long quotient;
    long remainder;
    char hexadecimal[20];
    if (print == 0)
        return (3);
    int j = 0;
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
            quotient = UINT_MAX - ((print * -1) - 1);
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    return (ft_strlen(hexadecimal));
}

int ft_intlen(int n)
{
    int len;
    len = 1;
    if (n < 0)
    {
        len = 2;
        n *= -1;
        while (n > 9)
        {
            len++;
            n /= 10;
        }
        return (len);
    }
    else
    {
        while (n > 9)
        {
            len++;
            n /= 10;
        }
        return (len);
    }
    return (-1);
}
void ft_put_x_up(long print, int min_c, int flag)
{
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    char *ulongmax;
    int j = 0;
    if (print == LONG_MIN)
    {
        longmin = "ffffffff";
        ft_putstr(longmin);
        return;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "ffffffff";
        ft_putstr(ulongmax);
        return;
    }
    if (print == 0)
        ft_putc('0');
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
        {
            quotient = UINT_MAX - ((print * -1) - 1);
        }
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    if (min_c > 0 && print != 0)
        print_x_times(min_c - (ft_intlen(print) - 1), '0');
    if (min_c > 0 && print == 0)
        print_x_times(min_c - 3, '0');
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}

int type_print(long print, int to_pad, int min_c, int size)
{
    if (to_pad > 0)
    {
        if (min_c > to_pad)
            to_pad = min_c;
        print_x_times(min_c - to_pad, ' ');
        ft_put_x_up(print, min_c, 2);
        return (0);
    }
    if (to_pad < 0)
    {
        if (min_c == 0)
        {
            ft_put_x_up(print, min_c, 2);
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        ft_put_x_up(print, min_c, 2);
        print_x_times((to_pad * -1) - min_c, ' ');
        return (0);
    }
    else
        ft_put_x_up(print, min_c, 2);
    return (0);
}

int main()
{
    /*     type_print(1021, -21, 10, ft_intlen(1021));
    printf("\n");
    printf("%-021.10x\n", 1021); */
    /*     type_print(-1011, -21, 0, ft_intlen(-1011));
    printf("\n");
    printf("%-021.0x\n", -1011); */
/*     type_print(0, -2, 2, ft_intlen(0));
    printf("\n");
    printf("%-2.2x\n", 0); */
/*     type_print(1, -3, 2, ft_intlen(1));
    printf("\n");
    printf("%-3.2x\n", 1); */
    printf("%.10s\n", "olaa");
    printf("%90s\n", "olaaaa");
    /* 21, 1021, 21, -1011)
    printf(" %-2.2x \n", 0); */
}
