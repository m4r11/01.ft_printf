/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/14 15:58:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putc(char c)
{
	write(1, &c, 1);
	counter(1);
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

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	return (x);
}

/* int ft_arglen(va_list TYPE)
{
	int i;
	static int x;
	if (!TYPE)
		return (x += 0);
	i = 0;
	while(&TYPE[i])
	{
		i++;
		x++;
	}
	debug_number(i,"i");
	debug_number(x, "x");
	return (x += i);
	return (0);
} */

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int ft_intlen_bonus(int n)
{
	int len;
	len = 1;
	while (n > 9)
	{
		len++;
		n /=10;
	}
	return (len);
}

int ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power != 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
	}
	return (result);
}

char *ft_strdup(const char *s1)
{
	char *s2;
	size_t i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

int counter(int n)
{
	static int res = 0;

	res += n;
	return(res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_ratoi(const char *str, int i)
{
	if (!*str || *str > '9' || *str < '0')
		return (i);
	i = i * 10 + (*str - '0');
	return (ft_ratoi(++str, i));
}

int			ft_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		return (-ft_ratoi(++str, 0));
	if (*str == '+')
		return (ft_ratoi(++str, 0));
	return (ft_ratoi(str, 0));
}

int			ft_simple_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == '-')
		str++;
	return (ft_ratoi(str, 0));
}

char	*print_x_times(int n, char c)
{
	//debug_number(n, "convertedn");
	while (n > 0)
	{
		ft_putc(c);
		n--;
	}
	return(0);
}

int    loop_through(char *flags, char *format, int j)
{
    int i;
    char found;

    int f;
    f = 0;

    while(format[j] != '%' && format[j] !='\0')
    {
		//debug_str(format, "format");
        if (format[j] == CONV_S[f])
            j++;
        i = 0;
        while (flags[i] != format[j] && flags[i] != '\0')
            i++;
        if (flags[i] == format[j])
        {
			/* debug_number(i, "i");
			debug_number(i, "j"); */
            return(i);
                break;
        }
        else 
            i = 0; 
            j++;
            f++;   
    }
    return(-1);
}

int  get_index(char *s1, char *s2)
{
    int j;
	int mini_index = INT_MAX;
	int len1 = ft_strlen(s1);
	char *start = ft_strchr(s2, '%');
	//debug_str(start, "start");
	int len2 = ft_strlen(start);
	//debug_number(len1, "len1");
	int i = 0;
    while(i < len2)
    {	
		i++;
		j = 0;
        while(j<len1)
        {
			j++;
            if(s2[i] == s1[j] && j < mini_index)
            {
				mini_index = j;
                return(j);
				break;
            }
        }
    }
	if (mini_index != j)
		return(NO_FORMAT);
    return(0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}