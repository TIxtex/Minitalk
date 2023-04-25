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
