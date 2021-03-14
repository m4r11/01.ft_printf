/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_x_times.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:41:10 by user              #+#    #+#             */
/*   Updated: 2021/03/12 19:43:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	print_x_times(int n, char c)
{
	int i; 
	i = 0; 
	while (n > 0)
	{
		printf("%c", c);
		n--;
	}
	return(0);
}

int main ()
{
    print_x_times(10, '0');
return(0);
}