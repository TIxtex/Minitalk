/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:57:45 by uherrero          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:36 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define BASE 10
#define ERR_ "ft_putnbr_fd(): invalid fd"

static void	ft_digit(unsigned int nu, int fd, char aux)
{
	aux = nu % BASE + '0';
	if (nu / BASE)
		ft_digit(nu / BASE, fd, aux);
	write(fd, &aux, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < ZERO)
		ft_puterror(ERR_);
	else
	{
		if (ZERO > n)
			n = -n * write(fd, "-", sizeof(char));
		ft_digit((unsigned int) n, fd, (char)fd);
	}
}
