#include "../minitalk.h"

int	main(int argc, char **argv)
{
	pid_t			pid_to_send;
	size_t			i;
	unsigned int	j;

	i = 0;
	if (argc != 3)
		ft_error("Introduce el PID y una string como argumentos");
	pid_to_send = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		j = 0;
		while (j++ < (unsigned int)argv[2][i])
		{
			if (kill(pid_to_send, SIGUSR1) != 0)
				ft_error("Error al mandar la señal");
			usleep(320);
		}
		if (kill(pid_to_send, SIGUSR2) != 0)
			ft_error("Error al mandar la señal");
		usleep(320);
		i++;
	}
	if (kill(pid_to_send, SIGUSR2) != 0)
		ft_error("Error al mandar la señal");
	return (0);
}
