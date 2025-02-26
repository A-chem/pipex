#include "../include/pipex.h"

void process_2(char **av, char **env, t_data *data)
{
    ft_close(data->fd[1]); 
    data->fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
         handle_errors(data->fd_out, "Error Opening File");
    ft_dup2(data->fd[0], 0, data->fd_out, "Dup2 Failed");
    ft_close(data->fd[0]);
    ft_dup2(data->fd_out, 1, data->fd[0], "Dup Failed");
    ft_close(data->fd_out);
    check_exec_cmd(av[3], env);
}

void process_1(char **av, char **env, t_data *data)
{
    ft_close(data->fd[0]);
    data->fd_in = open(av[1], O_RDONLY);
    handle_errors(data->fd_in, "Error Opening File");
    if (data->fd_in != -1 && av[1] != NULL && av[1][0] != '/') 
        ft_unlink(av[1]);
    ft_dup2(data->fd_in, 0, data->fd[1], "Dup Failed");
    ft_close(data->fd_in);
    ft_dup2(data->fd[1], 1, data->fd_in, "Dup Failed");
    ft_close(data->fd[1]);
    check_exec_cmd(av[2], env);
}

void    pipex(char **av, char **env, t_data *data)
{
    pid_t child_1;
    pid_t child_2;

    ft_pipe(&data, "Pipe Failed");
    child_1 = ft_fork(child_1, "Fork 1 Failed");
    if (child_1 == 0)
        process_1(av, env, data);
    child_2 = ft_fork(child_2, "Fork 2 Failed");
    if (child_2 == 0)
        process_2(av, env, data);
    ft_close(data->fd[1]);
    ft_close(data->fd[0]);
    ft_wait(child_1);
    ft_wait(child_2);
}


int main(int ac, char **av, char **env)
{
    t_data data;

 /*if (ac != 5)
    {
        perror("Wrong numbre of arguments");
        exit(1);
    }
     if (!*env || !env)
     {
        perror("env failed");
        exit(1);
     }*/
   pipex(av, env, &data);
   //check_exec_cmd(av[1], env);
}