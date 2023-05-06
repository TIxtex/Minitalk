/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:17:47 by uherrero          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:39 by uliherre         ###   ########.fr       */
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
