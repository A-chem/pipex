#include "../include/pipex_bonus.h"

int ft_open(int flag, int ac, char **av, t_data *data)
{
    if(ft_strncmp(av[1], "here_doc", 8) == 0)
    {
        if(ac < 6)
            exit(1);
        data->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
        handle_errors(data->fd_out, "Error Opening File");
        ft_here_doc(av, data);
        flag++;
    }
    else
    {
        data->fd_in = open(av[1], O_RDONLY);
        handle_errors(data->fd_in, "Error Opening File");
        ft_dup2(data->fd_in, 0, "Dup Failed");
        ft_close(data->fd_in);
         data->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        handle_errors(data->fd_out, "Error Opening File");
    }
    return flag;
}


void pipex(int ac, char **av, char **env, t_data *data)
{
    int i;

   
    i = ft_open(1, ac, av, data);
    while (++i < ac - 1)
		ft_process(av[i], env, (i + 1 == ac - 1), data);
    ft_close(data->fd_out);
    while (waitpid(-1, NULL, 0) != -1)
        ;
}
int main(int ac, char **av, char **env)
{
    t_data data;

 if (ac < 5)
    {
        ft_putstr("Wrong numbre of arguments");
        exit(1);
    }
     if (!*env || !env)
     {
        ft_putstr("env failed");
        exit(1);
     }
   pipex(ac, av, env, &data);
}