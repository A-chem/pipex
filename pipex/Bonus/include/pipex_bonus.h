#ifndef  PIPEX_BONUS_H
#define  PIPEX_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "get_next_line_bonus.h"

typedef struct s_data
{
    int     fd[2];
    int     fd_in;
    int     fd_out;
} t_data; 

void    ft_putstr(const char *str);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_strcmp( char *s1,  char *s2);
char	**ft_split(char *s, char c);
void	handle_errors(int fd, char *str);
void    ft_pipe(t_data **data, char *str);
pid_t   ft_fork(pid_t child, char *str);
void    ft_close(int fd);
void	ft_dup2(int fd_src, int fd_dest, char *str);
void    ft_wait(void);
void    ft_here_doc(char **av, t_data *data);
void    ft_process(char *cmd, char **env, bool condition, t_data *data);
void    check_exec_cmd(char *cmd, char **env);
int     ft_check_path_cmd(char *cmd);
char    *ft_found_cmd (char *cmd, char **path);
char    *fet_path(char **env);
void    pars_cmd_1(char *cmd);
void    pars_cmd_2(char **cmd_split, char **env);
void    pars_cmd_3(char **cmd_split, char **env);


#endif