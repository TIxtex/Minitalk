/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:17:47 by uherrero          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:26 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define ERR_ "ft_putendl_fd NULL pointer or fd < 0"

void	ft_putendl_fd(char *s, int fd)
{
	if (NULL != s && fd >= ZERO)
	{
		write(fd, s, ft_strlen(s) * sizeof(char));
		write(fd, "\n", sizeof(char));
	}
	else
		ft_puterror(ERR_);
}
