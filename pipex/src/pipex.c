#include "../include/pipex.h"
void process_2(char **av, char **env, t_data *data)
{
    close(data->fd[1]); 
    data->fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
    if (data->fd_out == -1) 
        Error_open("open failed", data->fd[0]);
    if (dup2(data->fd[0], 0) == -1)
        Error_dup("dup2 failed", data->fd[0], data->fd_out);
    close(data->fd[0]);
    if (dup2(data->fd_out, 1) == -1)
        Error_dup("dup2 failed", data->fd[0], data->fd_out);
    close(data->fd_out);
    check_exec_cmd(av[3], env);
}

void process_1(char **av, char **env, t_data *data)
{
    close(data->fd[0]);
    data->fd_in = open(av[1], O_RDONLY);
    if (data->fd_in == -1)
        Error_open("open failed", data->fd[1]);
    if (dup2(data->fd_in, 0) == -1)
        Error_dup("dup2 failed", data->fd[1] , data->fd_in);
    close(data->fd_in);
    if (dup2(data->fd[1], 1) == -1)
        Error_dup("dup2 failed", data->fd[1] , data->fd_in);
    close(data->fd[1]);
    check_exec_cmd(av[2], env);
}

void    pipex(char **av, char **env, t_data *data)
{
    pid_t child_1;
    pid_t child_2;

    if (pipe(data->fd) == -1)
        Error_pipe("pipe failed");
    child_1 = fork();
    if (child_1 == -1)
        handle_error ("fork failed");
    if (child_1 == 0)
        process_1(av, env, data);
    child_2 = fork();
    if (child_2 == -1)
        handle_error ("fork failed");
    if (child_2 == 0)
        process_2(av, env, data);
    close(data->fd[1]);
    close(data->fd[0]);
    waitpid(child_1, NULL, 0); 
    waitpid(child_2, NULL, 0);
}
int main(int ac, char **av, char **env) 
{
 
    t_data data;
    

    if (!*env)
        handle_error("envp failed");
    if (ac != 5)
        handle_error("Wrong number of arguments");
    pipex (av, env, &data);
 }