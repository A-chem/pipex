#include "../include/pipex.h"


char *fet_path(char **env)
{
    int i;
    char *path;

    if (!env)
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
char *ft_found_cmd (char *cmd, char **path)
{
    int i;
    char *cmd_path_join;
    char *cmd_path_join_2;

    i = 0;
    while (path[i])
    {
        cmd_path_join = ft_strjoin(path[i], "/");
        cmd_path_join_2 = ft_strjoin(cmd_path_join, cmd);
        if (access(cmd_path_join_2, X_OK) == 0)
            return (cmd_path_join_2);
        i++;
    }
    return NULL;
}

void    check_exec_cmd(char *cmd, char **env)
{
    char    **cmd_split;
    char    **path;
    char    *path_cmd;

    path = ft_split(fet_path(env), ':');
    cmd_split = ft_split(cmd, ' ');
    if (!cmd_split || !path)
        exit(1);
    if (cmd_split[0][0] == '/' && cmd_split[0][0] != '/')
        ft_exec (cmd_split[0], cmd_split, env);
    else if (cmd_split[0][0] == '/' && cmd_split[0][1] == '/')
    {
        perror("Command not found");
        exit(1);
    }
    path_cmd = ft_found_cmd(cmd_split[0], path);
    if (access (cmd_split[0], X_OK) == 0)
        path_cmd = cmd_split[0];
    else
     path_cmd = ft_found_cmd(cmd_split[0], path);
    if (!path_cmd)
    {
        perror("Command not found");
        exit(1);
    }
    ft_exec(path_cmd , cmd_split, env);
}
