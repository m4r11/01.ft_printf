/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:11:31 by user              #+#    #+#             */
/*   Updated: 2021/03/24 12:17:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

