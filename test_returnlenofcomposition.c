/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_returnlenofcomposition.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:32:59 by user              #+#    #+#             */
/*   Updated: 2021/03/17 13:38:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# define CONV_S "dixXufeEsScgopn"
# define DIR_S "*-+ 0hljz.#123456789"

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

int		ft_composition(char *s, int start, char *dir, char *flag)
{
	int i;
	i = start;
    int j; 
    int k;
    int len = 0;
    int size = ft_strlen(s);
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

int     main()
{
    int r, r2, r3;
    char *s, *s2, *s3;
    s = " %c ";
    s2 = " %-10c";
    s3 = "test %d";

    r = ft_composition(s, 1, DIR_S, CONV_S);
    r2 = ft_composition(s2, 1, DIR_S, CONV_S);
    r3 = ft_composition(s3, 5, DIR_S, CONV_S);

    printf("%d\n%d\n%d\n", r, r2, r3);
}