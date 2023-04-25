/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:32:58 by uherrero          #+#    #+#             */
/*   Updated: 2022/03/08 14:34:55 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define ERR_ "ft_putchar_fd(): invalid fd"

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
		write(fd, &c, sizeof(char));
	else
		ft_puterror(ERR_);
}
