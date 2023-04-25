/**	SERVER	**/
#include "../minitalk.h"

static int ft_check_character(char character, siginfo_t *info)
{

	if ('\1' == character)
	{
		ft_putnbr_fd((int) info->si_pid, STDOUT_FILENO);
		ft_putendl_fd("\n:	Send a message.\n–––", STDOUT_FILENO);
	}
	else if ('\0' == character)
	{
		if (ZERO != kill(info->si_pid, SIGUSR2))
				ft_puterror("send SIGUSR2");
		ft_putendl_fd("\n–––\nEnd of Message.", STDOUT_FILENO);
		return (ZERO);
	}
	return (TRUE);
}

static void	ft_handler_normal(int sig, siginfo_t *info, void *var)
{
	static unsigned int	count = ZERO;
	static char			character = ZERO;

	(void)var;
	if (SIGUSR1 == sig)
		character |= (TRUE << count);
	else if (SIGUSR2 == sig)
		character &= ~(TRUE << count);
	if (__CHAR_BIT__ == ++count)
	{
		count = ZERO;
		ft_putchar_fd(character, STDOUT_FILENO);
		if (ZERO == ft_check_character(character, info))
			return ;
		character = ZERO;
	}
	if (ZERO != kill(info->si_pid, SIGUSR1))
		ft_puterror("send SIGUSR1");
}

static void ft_normal(int sig)
{
	(void) sig;
	ft_puterror("catch normal SIGUSR1");
}

int	main(void)
{
	struct sigaction	normal;

	sigemptyset(&normal.sa_mask);
	sigaddset(&normal.sa_mask, SIGUSR1);
	sigaddset(&normal.sa_mask, SIGUSR2);
	normal.sa_flags = SA_ONSTACK | SA_SIGINFO;
	normal.sa_handler = (void *) &ft_normal;
	normal.sa_sigaction = (void *) &ft_handler_normal;
	if (sigaction(SIGUSR1, &normal, NULL))
		ft_puterror("sigaction SIGUSR1");
	if (sigaction(SIGUSR2, &normal, NULL))
		ft_puterror("sigaction SIGUSR2");
	ft_print_pid();
	while (TRUE)
		sleep(42);
	return (42);
}
