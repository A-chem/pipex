#include "../include/pipex.h"

void Error_pipe (char *str)
{
        perror(str);
        exit(1);
}
void    Error_dup (char *str, int fd_pipe, int fd)
{
    close (fd_pipe);
    close (fd);
    perror(str);
    exit(1);
}
void Error_open (char *str, int fd_pipe)
{
    close (fd_pipe);
    perror(str);
    exit(1);
}
void ft_exec (char *path , char **cmd_split , char **env)
{
    if (execve(path, cmd_split, env) == -1)
    {
        perror("execve failed");
        exit(1);
    }
}
void Error_fd(char *str)
{
    perror(str);
    exit(1);
}