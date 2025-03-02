#include "../include/pipex_bonus.h"

void ft_process(char *cmd, char **env, bool condition, t_data *data, int i, char **av)
{
    int child;
    ft_pipe(&data, "Pipe Failed");
    child = ft_fork(child, "Fork 1 Failed");
    if (child == 0)
    {
        ft_close(data->fd[0]);
        if (i == 2)
        {
            data->fd_in = open(av[1], O_RDONLY);
              if (data->fd_in == -1)
              {
                    ft_putstr("Error Opening File");
                    exit(1);
              }
                ft_dup2(data->fd_in, 0, "Dup Failed");
                ft_close(data->fd_in);
        }
        else if(condition)
        {
            ft_dup2(data->fd_out, 1, "Dup Failed");
			ft_close(data->fd_out);
        }
        else
        {
            ft_dup2(data->fd[1], 1, "Dup failed");
            ft_close(data->fd[1]);
        }
        check_exec_cmd(cmd, env);
    }
    else
    {
            ft_close(data->fd[1]);
            ft_dup2(data->fd[0], 0, "Dup Failed");
            ft_close(data->fd[0]);
    }


}