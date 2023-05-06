/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:03:01 by uherrero          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:47 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static void	*ft_calloc(size_t count, size_t size)
{
	register char	*new;
	register size_t	bytes;
	register size_t	x;

	bytes = count * size;
	new = (char *) malloc(bytes);
	if (NULL != new)
	{
		x = ZERO;
		while (x < bytes)
		{
			new[x] = '\0';
			x++;
		}
	}
	return ((void *) new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	register char	*nw_str;
	register char	*start;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	nw_str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	start = nw_str;
	if (NULL != nw_str)
	{
		while ('\0' != *s1)
			*(nw_str++) = *(s1++);
		while ('\0' != *s2)
			*(nw_str++) = *(s2++);
	}
	return (start);
}
