#include "../include/pipex.h"


static char *fet_path(char **env)
{
    int i;
    char *path;

    if (!*env || !env)
        return (NULL);
    i = 0;
    path = "PATH=";
    while (env[i])
    {
        if (ft_strncmp(env[i], path, 5) == 0)
            return (env[i] + 5);
        i++;
    }
    return (NULL);
}
static char *ft_found_cmd (char *cmd, char **path)
{
    int i;
    char *cmd_path_join;
    char *cmd_path_join_2;

    i = 0;
    while (path[i])
    {
        cmd_path_join = ft_strjoin(path[i], "/");
        cmd_path_join_2 = ft_strjoin(cmd_path_join, cmd);
         free(cmd_path_join);
        if (access(cmd_path_join_2, X_OK) == 0)
        {
           
            return (cmd_path_join_2);
        }
        free(cmd_path_join_2);
        i++;
    }
    return NULL;
}
void ft_exec (char *path , char **cmd_split , char **env)
{
    if (execve(path, cmd_split, env) == -1)
    {
        perror("execve failed");
        exit(1);
    }
}
int ft_check_path_cmd(char *cmd)
{
    int i = 0;
    while(cmd[i])
    {
        if(cmd[i] == '/')
            return 1;
        i++;
    }
    return 0;
}
void check_exec_cmd(char *cmd, char **env)
{
    char **cmd_split;
    char **path;
    char *path_cmd;

    // Split the command into arguments
    cmd_split = ft_split(cmd, ' ');
    if (cmd[0] == ' ' || cmd[ft_strlen(cmd) - 1] == ' ' || (cmd[0] == '.' && ft_check_path_cmd(cmd) == 0))
    {
        write(2, "Command not found\n", 18);
        exit(1);
    }
    else if (ft_check_path_cmd(cmd) == 1)
    {

        if (access(cmd_split[0], F_OK) == -1)
        {
            write(2, "No such file or directory\n", 26);
            exit(1);
        }
        if (access(cmd_split[0], X_OK) == -1)
        {
            write(2, "Command is not executable\n", 26);
            exit(1);
        }
        if (execve(cmd_split[0], cmd_split, env) == -1)
        {
            perror("execve failed");
            exit(1);
        }
    }
    else
    {
        path = ft_split(fet_path(env), ':');
        if (!path)
        {
            write(2, "PATH not found in environment\n", 28);
            exit(1);
        }

        path_cmd = ft_found_cmd(cmd_split[0], path);
        if (!path_cmd)
        {
            write(2, "No such file or directory\n", 26);
            exit(1);
        }

        if (execve(path_cmd, cmd_split, env) == -1)
        {
            perror("execve failed");
            exit(1);
        }
    }
}
