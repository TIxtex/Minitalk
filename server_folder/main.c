#include "../minitalk.h"

static void	ft_handler_sa(int sig)
{
	static unsigned int	count = 0;

	if (30 == sig)
		count++;
	else if (31 == sig)
	{
		if (0 == count)
			write(STDOUT_FILENO, "\n", 1);
		else
		{
			write(STDOUT_FILENO, &count, sizeof(char));
			count = 0;
		}
	}
}

int	main(void)
{
	pid_t				pidserver;
	struct sigaction	sa;

	sa.sa_handler = &ft_handler_sa;
	sa.sa_flags = SA_ONSTACK;
	pidserver = getpid();
	ft_putnbr_fd(pidserver, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_error("Error al asignar accion");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_error("Error al asignar accion");
	while (1)
		sleep(0);
	return (0);
}
