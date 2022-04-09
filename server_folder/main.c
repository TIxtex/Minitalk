#include "../minitalk.h"

static void	ft_handler_normal(int signal)
{
	static unsigned int	count = ZERO;
	static char			character = ZERO;

	if (SIGUSR1 == signal)
		((character) |= (TRUE << (count)));
	else if (SIGUSR2 == signal)
		((character) &= ~(TRUE << (count)));
	if (__CHAR_BIT__ == ++count)
	{
		count = ZERO;
		ft_putchar_fd(character, STDOUT_FILENO);
	}
}

static void	ft_print_pid(void)
{
	ft_putnbr_fd((int)getpid(), STDOUT_FILENO);
	ft_putendl_fd(" <-SERVER_PID\n", STDOUT_FILENO);
}

int	main(void)
{
	struct sigaction	normal;

	normal.sa_handler = &ft_handler_normal;
	normal.sa_flags = SA_ONSTACK;
	if (sigaction(SIGUSR1, &normal, NULL))
		ft_puterror("Error al asignar accion");
	if (sigaction(SIGUSR2, &normal, NULL))
		ft_puterror("Error al asignar accion");
	ft_print_pid();
	while (TRUE)
		;
	return (42);
}
