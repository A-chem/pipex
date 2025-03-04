#include "../include/pipex.h"
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
void pars_cmd_1(char *cmd)
{
     if ((cmd[0] == ' ' || cmd[ft_strlen(cmd) - 1] == ' ' || cmd[0] == '.' )&& ft_check_path_cmd(cmd) == 0)
    {
        ft_putstr(cmd);
        ft_putstr(": Command not found");
        ft_putstr("\n");
        exit(1);
    }

}
void pars_cmd_2(char **cmd_split, char **env)
{
       if (access(cmd_split[0], F_OK) == -1)
        {
            ft_putstr("No such file or directory: ");
            ft_putstr(cmd_split[0]);
            ft_putstr("\n");
            ft_double_free (cmd_split);
            exit(1);
        }
        if (access(cmd_split[0], X_OK) == -1)
        {
            ft_putstr("Permission Denied: ");
            ft_putstr(cmd_split[0]);
            ft_putstr("\n");
            ft_double_free (cmd_split);
            exit(1);
        }
        if (execve(cmd_split[0], cmd_split, env) == -1)
        {
            ft_putstr("Execve Failed");
            ft_double_free (cmd_split);
            exit(1);
        }
}



void pars_cmd_3(char **cmd_split, char **env)
{ 
    char **path;
    char *path_cmd;

    path = ft_split(fet_path(env), ':');
        if (!path)
        {
            write(2, "PATH not found in environment\n", 28);
            ft_double_free (cmd_split);
            ft_double_free (path);
            exit(1);
        }
        path_cmd = ft_found_cmd(cmd_split[0], path);
        if (!path_cmd)
        {
            ft_putstr(cmd_split[0]);
            ft_putstr(": Command not found");
            ft_putstr("\n");
            ft_double_free (cmd_split);
            ft_double_free (path);
            free(path_cmd);
            exit(1);
        }
        if (execve(path_cmd, cmd_split, env) == -1)
        {
            ft_putstr("Execve Failed");
            ft_double_free (cmd_split);
            ft_double_free (path);
            free(path_cmd);
            exit(1);
        }
}
void ft_double_free (char **str)
{
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}