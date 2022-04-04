#include "../minitalk.h"

static void	ft_send_str(pid_t pid, char *str)
{
	int	b;

	while (*str)
	{
		b = ZERO;
		while (b < 8)
		{
			if ((*str) & (1 << (b)))
			{
				if (kill(pid, SIGUSR1))
					ft_error("Error al mandar la señal");
			}
			else
			{
				if (kill(pid, SIGUSR2))
					ft_error("Error al mandar la señal");
			}
			b++;
			usleep(64);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_error("Introduce el PID y una string como argumentos");
	ft_send_str(ft_atoi(argv[1]), argv[2]);
	return (42);
}
