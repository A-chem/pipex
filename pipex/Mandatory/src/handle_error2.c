#include "../include/pipex.h"

void ft_wait(int pid)
{
	pid_t	terminated_pid;

	terminated_pid = waitpid(pid, NULL, 0);
	if (terminated_pid == -1)
	{
		ft_putstr("Error waiting");
		exit(1);
	}
}
void ft_unlink(char *str)
{
	if(unlink(str) == -1)
	{
		ft_putstr("Error Unlinking File");
		exit(1);
	}
}
