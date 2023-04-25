/**	CLIENT	**/
#include "../minitalk.h"
#define F_DELAY 100

t_data	message;

static void	ft_send_bit(int sig)
{
	static size_t	b = ZERO;

	usleep(F_DELAY);
	if (*message.msg & (TRUE << (b)))
	{
		if (ZERO != kill(message.server_pid, sig))
			ft_puterror("send SIGUSR1");
	}
	else
	{
		if (ZERO != kill(message.server_pid, SIGUSR2))
			ft_puterror("send SIGNUSR2");
	}
	if (__CHAR_BIT__ == ++b)
	{
		if ('\0' != *message.msg)
			++message.msg;
		b = ZERO;
	}
}

static void	ft_end(int sig)
{
	(void)sig;
	ft_putendl_fd("OK - Msg recived from server", STDOUT_FILENO);
	free(message.ini);
	message.ini = NULL;
	message.msg = NULL;
	exit (42);
}

static void	ft_check_args(int argc, char **argv)
{
	if (3 != argc)
		ft_puterror("Enter the PID followed by a string as arguments");
	/** check pid and non null str**/
	message.server_pid = (pid_t) ft_atoi(argv[1]);
	message.msg = ft_strjoin("\1", (const char *) argv[2]);
	message.ini = message.msg;
}

int	main(int argc, char **argv)
{
	struct sigaction	ack;
	struct sigaction	end;

	ft_check_args(argc, argv);
	ack.sa_handler = &ft_send_bit;
	ack.sa_flags = SA_ONSTACK;
	end.sa_handler = &ft_end;
	end.sa_flags = SA_ONSTACK;
	if (sigaction(SIGUSR1, &ack, NULL))
		ft_puterror("sigaction SIGUSR1");
	if (sigaction(SIGUSR2, &end, NULL))
		ft_puterror("sigaction SIGUSR2");
	ft_send_bit(SIGUSR1);
	while (TRUE)
		sleep(42);
	return (42);
}
