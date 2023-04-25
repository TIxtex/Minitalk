/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulherrer <ulherrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:17:47 by uherrero          #+#    #+#             */
/*   Updated: 2022/06/04 14:24:16 by ulherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define ERR_ "ft_putstr_fd(): invalid fd or NULL pointer"

void	ft_putstr_fd(char *s, int fd)
{
	if (NULL != s && fd >= ZERO)
		write(fd, s, ft_strlen(s) * sizeof(char));
	else
		ft_puterror(ERR_);
}
