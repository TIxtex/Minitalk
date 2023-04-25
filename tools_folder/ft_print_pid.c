#include "tools.h"

void	ft_print_pid(void)
{
	ft_putnbr_fd((int) getpid(), STDOUT_FILENO);
	ft_putendl_fd("	<-	PID.", STDOUT_FILENO);
}
