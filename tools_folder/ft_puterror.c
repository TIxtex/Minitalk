/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:09:29 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:30 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#define MSG_E "Error: "
#define MY_E "ft_puterror(): NULL pointer."

void	ft_puterror(const char *error)
{
	if (NULL != error)
	{
		write(STDERR_FILENO, MSG_E, sizeof(MSG_E));
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", sizeof(char));
	}
	else
		ft_puterror(MY_E);
	exit(-42);
}
