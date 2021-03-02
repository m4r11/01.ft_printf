/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:33:15 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/02 15:48:51 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB:
** SYN: allocates sufficient memory for a copy of the string s1 to s2
** DESC: allocates dynamically, copies, returns a pointer to it.
** (｡◕‿◕｡)
*/

#include "ft_print.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
