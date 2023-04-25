/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:09:52 by uherrero          #+#    #+#             */
/*   Updated: 2022/07/04 15:41:22 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define BASE 10

static int	ft_isspace(int c)
{
	if (' ' == c || (unsigned) c - '	' < 5)
		return (TRUE);
	return (FALSE);
}

static int	ft_isdigit(int c)
{	
	if ((unsigned) c - '0' < BASE)
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	register unsigned int	value;
	register int			negative;

	value = ZERO;
	negative = TRUE;
	while (TRUE == ft_isspace(*str))
		++str;
	if ('+' == *str || '-' == *str)
		if ('-' == *(str++))
			negative = -TRUE;
	while (TRUE == ft_isdigit(*str))
		value = value * BASE + *(str++) - '0';
	return ((int) value * negative);
}
