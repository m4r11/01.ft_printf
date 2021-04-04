/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_int_combos_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:02:38 by user              #+#    #+#             */
/*   Updated: 2021/03/29 18:57:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ->| %0*.* |<- */
char zero_star_dot_star(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.min_c = va_arg(args2, int);
    dv.x = va_arg(args2, int);
    if (dv.width > dv.min_c && dv.x < 0)
        print_x_times(dv.width - dv.min_c - 1, ' ');
    if (dv.x < 0)
    {
        dv.x *= -1;
        ft_putc('-');
    }
    print_x_times(dv.min_c - ft_intlen(dv.x), '0');
    ft_putnbr(dv.x);
    return (0);
}
/* ->| %0*.0 |<- */
char zero_star_dot_digi(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.min_c = ft_atoi(&to_convert[3]);
    dv.x = va_arg(args2, int);
    /*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    debug_number(dv.x, "x"); */
    if (dv.x == INT_MAX)
    {
        ft_putnbr(dv.x);
        if (dv.width < 0)
            dv.width *= -1;
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        return (0);
    }
    if (dv.x == INT_MIN)
    {
        if (dv.width < 0)
            dv.width *= -1;
        print_x_times(dv.width - dv.min_c - 1, ' ');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.width > dv.min_c && dv.x < 0)
    {
        print_x_times(dv.width - dv.min_c - 1, ' ');
        return (0);
    }
    if (dv.x < 0)
    {
        ft_putnbr(dv.x);
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        if (dv.width < 0)
            dv.width *= -1;
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        return (0);
    }
    if (dv.x >= 0 && dv.width > 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.x == 0 && dv.width < 0)
    {
        dv.width *= -1;
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.width > dv.min_c)
    {
        if (dv.x > 0)
        {
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x);
            return (0);
        }
        if (dv.x < 0)
        {
            ft_putc('-');
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x * -1);
            return (0);
        }
        return (0);
    }
    print_x_times(dv.min_c - ft_intlen(dv.x), '0');
    ft_putnbr(dv.x);
    return (0);
}
/* ->| %0*d |<- */
char zero_star_flag(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.x = va_arg(args2, int);
    if (dv.x < 0)
    {
        dv.x *= -1;
        ft_putc('-');
    }
    print_x_times(dv.width - ft_intlen(dv.x) - 1, '0');
    ft_putnbr(dv.x);
    return (0);
}
/* ->| %010.4d |<- */
char zero_2digi_dot_flag(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = ft_atoi(&to_convert[1]);
    dv.min_c = ft_atoi(&to_convert[4]);
    dv.x = va_arg(args2, int);
    /*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    debug_number(dv.x, "x");
    debug_number(ft_intlen(dv.x), "len"); */
    if (dv.width == dv.min_c)
    {
        if (dv.x < 0)
        {
            ft_putc('-');
            print_x_times(dv.min_c - ft_intlen(dv.x * -1), '0');
            ft_putnbr(dv.x * -1);
            return (0);
        }
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.x == 0 && dv.min_c == 0 && dv.width > 0)
    {
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.min_c == 0 && dv.width > 0)
    {
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.min_c < ft_intlen(dv.x))
    {
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.min_c >= ft_intlen(dv.x))
    {
        if (dv.x < 0)
        {
            print_x_times(dv.width - dv.min_c - 1, ' ');
            ft_putc('-');
            print_x_times(dv.min_c - ft_intlen(dv.x * -1), '0');
            ft_putnbr(dv.x * -1);
            return (0);
        }
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        return (0);
    }
    return (0);
}
/* ->| %01.4d |<- */
char zero_1digit_dot_flag(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = ft_atoi(&to_convert[1]);
    dv.min_c = ft_atoi(&to_convert[3]);
    dv.x = va_arg(args2, int);
    /*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    debug_number(dv.x, "x");
    debug_number(ft_intlen(dv.x), "len"); */

    if (dv.min_c == 0 && dv.x > 0)
    {
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.min_c == 0 && dv.x < 0)
    {
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.x < 0)
    {
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.min_c < ft_intlen(dv.x))
        {
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            ft_putc('-');
            print_x_times(dv.min_c - ft_intlen(dv.x * -1), '0');
            ft_putnbr(dv.x * -1);
            return (0);
        }
        if (dv.width > dv.min_c && dv.min_c >= ft_intlen(dv.x))
            print_x_times(dv.width - dv.min_c - 1, ' ');
        ft_putc('-');
        print_x_times(dv.min_c - ft_intlen(dv.x * -1), '0');
        ft_putnbr(dv.x * -1);
        return (0);
        /*  youarehere */
    }
    if (dv.min_c == 0 && dv.x == 0)
    {
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            print_x_times(dv.width, ' ');
            return (0);
        }
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.x < 0 && dv.width < 0)
    {
        ft_putnbr(dv.x);
        dv.width *= -1;
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        return (0);
    }
    if (dv.x < 0)
    {
        print_x_times(dv.width - dv.min_c - 1, ' ');
        ft_putnbr(dv.x);
        print_x_times(ft_intlen(dv.x) - dv.width, '0');
        return (0);
    }
    if (dv.x == 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        ft_putnbr(dv.x);
        print_x_times(dv.min_c - 1, '0');
        return (0);
    }
    if (dv.min_c > 0 && dv.x > 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.width - dv.min_c - ft_intlen(dv.x) - 1, '0');
        ft_putnbr(dv.x);
        return (0);
    }
    print_x_times(dv.width - dv.min_c, ' ');
    ft_putnbr(dv.x);
    print_x_times(ft_intlen(dv.x) - dv.width, '0');
    return (0);
    return (0);
}
