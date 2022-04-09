#include "../minitalk.h"

static void	ft_send_str(pid_t pid, char *str)
{
	int	b;

	while (*str)
	{
		b = ZERO;
		while (b < __CHAR_BIT__)
		{
			if ((*str) & (TRUE << (b)))
			{
				if (kill(pid, SIGUSR1))
					ft_puterror("Error al mandar la señal");
			}
			else
			{
				if (kill(pid, SIGUSR2))
					ft_puterror("Error al mandar la señal");
			}
			++b;
			usleep(64);
		}
		++str;
	}
}

int	main(int argc, char **argv)
{
	if (3 != argc)
		ft_puterror("Introduce el PID seguido de una string como argumentos");
	ft_send_str((pid_t)ft_atoi(argv[1]), argv[2]);
	return (42);
}
