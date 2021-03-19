/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:13:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/02 17:17:05 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXARGS 31

void debug_str(const char *s, char *name);
void debug_number(int i, char *name);

void ft_putc(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putc(str[i]);
		++i;
	}
}

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	debug_number(x, "X");
	return (x);
}


int ft_test(char *format, ...)
{
	va_list args, args2;
	char *t;
	char *next;
	va_start(args, format);
	va_copy(args2, args);
	size_t i;

	i = 0;
	t = format;
	while (t[i])
	{
		if (t[i] != '%')
		{
			ft_putc(t[i]);
		}
		else
		{
			i++;
			if (t[i] == 's')
			{
				next = va_arg(args2, char *);
				ft_putstr(next);
			}
		}
		//ft_putstr("\nBreak here\n");
		/* ft_putstr(va_arg(args, char *)); */
		i++;
	}
	/* next = va_arg(args2, char *);
	ft_putstr(next);
	next = va_arg(args2, char *);
	ft_putstr(next); */
	va_end(args);
	return (0);
}

/* int ft_test(int count, ...)
{
    va_list args;
    va_start(args, count);

    while (count--)
    {
        ft_putstr(va_arg(args, char *));
		ft_putstr("\n");
    }
    va_end(args);
return(0);
} */

int main()
{
	ft_test("i want to say %s to %s", "hello", "catarina");
	return (0);
}