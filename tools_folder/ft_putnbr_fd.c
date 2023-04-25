/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:57:45 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/04 14:23:58 by ulherrer         ###   ########.fr       */
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
