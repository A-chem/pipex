
#include "../include/pipex.h"

void	handle_errors(int fd, char *str)
{
	if (fd == -1)
	{
		ft_putstr(str);
		exit(1);
	}
}


void	ft_dup2(int fd_src, int fd_dest, int fd_close, char *str)
{
    if(dup2(fd_src, fd_dest) == -1)
	 {
        ft_putstr(str);
        ft_close(fd_src);
        ft_close (fd_close);
        exit(1);
    }
}

void ft_close(int fd)
{
    if(close(fd) == -1)
    {
        ft_putstr("Error closing file\n");
        exit(1);
    }
}
void ft_pipe(t_data **data, char *str)
{
     if (pipe((*data)->fd) == -1)
    {
        ft_putstr(str);
        exit(1);
    }
}

pid_t ft_fork(pid_t child, char *str)
{
    child = fork();
    if( child== -1)
    {
        ft_putstr(str);
        exit(1);
    }
    return child;
}