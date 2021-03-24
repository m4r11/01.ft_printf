/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:39:56 by user              #+#    #+#             */
/*   Updated: 2021/03/24 12:16:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_putstr_limit(char *str, int limit)
{
	t_struct v;
	int i;

	i = 0;
	while ((str[i]) < str[limit])
	{
		ft_putc(str[i]);
		++i;
		//counter(1);
	}
	return(0);
}

int		ft_putcharfrom(char *s, int start, char *dir, char *flag)
{
	int i;
	i = start;
    int j; 
    int k;
    int len = 0;
    while(s[i] != '\0')
    {
        j = 0;
        while(dir[j] != '\0')
        {
            if (dir[j] == s[i])
            {
                len+=1;
                break;
            }
            j++;
        }
        k = 0;
        while(flag[k] != '\0')
        {
            if (flag[k] == s[i])
            {
                len+=1;
                break;
            }
            k+=1;
        }
        i++;
    }
	return(len);
}

int   print_the_middle(char *input, int flag1_end)
{
    int start;
    int middle;
    int end;

    start = ft_intstrchr_flag(input, '%', 0);
    //printf("start : %d\n" ,start);
    end = ft_intstrchr(input, '%', start);
    //printf("end : %d\n", end);
    middle = flag1_end;
    //printf("middle : %d\n", middle);
    if (middle == 0)
        return(0);
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    return(0);
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