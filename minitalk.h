/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:10:12 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 13:10:13 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "tools_folder/tools.h"
# include <signal.h>

typedef struct s_data
{
	pid_t	server_pid;
	char	*ini;
	char	*msg;
}			t_data;

#endif
