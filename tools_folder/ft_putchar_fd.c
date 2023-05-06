/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:32:58 by uherrero          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:23 by uliherre         ###   ########.fr       */
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
