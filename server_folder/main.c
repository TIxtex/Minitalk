#include "../minitalk.h"

static void	ft_handler_normal(int sig)
{
	static unsigned int	count = 0;
	static char			character = 0;

	if (30 == sig)
		((character) |= (1 << (count)));
	else if (31 == sig)
		((character) &= ~(1 << (count)));
	if (8 == ++count)
	{
		ft_putchar_fd(character, STDOUT_FILENO);
		count = 0;
	}
}

static void	ft_print_pid(void)
{
	pid_t	pidserver;

	pidserver = getpid();
	ft_putnbr_fd(pidserver, STDOUT_FILENO);
	ft_putendl_fd(" <-SERVER_PID", STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}

int	main(void)
{
	struct sigaction	normal;

	normal.sa_handler = &ft_handler_normal;
	normal.sa_flags = SA_ONSTACK;
	if (sigaction(SIGUSR1, &normal, NULL) != 0)
		ft_error("Error al asignar accion");
	if (sigaction(SIGUSR2, &normal, NULL) != 0)
		ft_error("Error al asignar accion");
	ft_print_pid();
	while (1)
		sleep(0);
	return (1);
}
