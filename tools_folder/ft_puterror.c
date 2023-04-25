#include "tools.h"
#define MSG_E "Error: "
#define MY_E "ft_puterror(): NULL pointer."

void	ft_puterror(const char *error)
{
	if (NULL != error)
	{
		write(STDERR_FILENO, MSG_E, sizeof(MSG_E));
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", sizeof(char));
	}
	else
		ft_puterror(MY_E);
	exit(-42);
}
