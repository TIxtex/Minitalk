/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:09:17 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 13:09:18 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_print_pid(void)
{
	ft_putnbr_fd((int) getpid(), STDOUT_FILENO);
	ft_putendl_fd("	<-	PID.", STDOUT_FILENO);
}
