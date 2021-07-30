#include "../minitalk.h"

static void	ft_send_str(pid_t pid, char *str)
{
	int	b;

	while (*str)
	{
		b = -1;
		while (++b < 8)
		{
			if ((*str) & (1 << (b)))
			{
				if (kill(pid, SIGUSR1) != 0)
					ft_error("Error al mandar la señal");
			}
			else
				if (kill(pid, SIGUSR2) != 0)
					ft_error("Error al mandar la señal");
			usleep(64);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t			pid_to_send;

	if (argc != 3)
		ft_error("Introduce el PID y una string como argumentos");
	pid_to_send = ft_atoi(argv[1]);
	ft_send_str(pid_to_send, argv[2]);
	return (1);
}
