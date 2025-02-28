#include "../include/pipex_bonus.h"

void ft_wait(void)
{
	pid_t	terminated_pid;

	terminated_pid = wait(NULL);
	if (terminated_pid == -1)
	{
		ft_putstr("Error waiting");
		exit(1);
	}
}