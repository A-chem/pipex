#ifndef  PIPEX_H
#define  PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_data
{
    int     fd[2];
    int     fd_in;
    int     fd_out;
} t_data; 

size_t	ft_strlen(const char *s);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *s, char c);
void ft_putstr(const char *str);
void	handle_errors(int fd, char *str);
void	ft_dup2(int fd_src, int fd_dest, int fd_close, char *str);
void ft_close(int fd);
void ft_pipe(t_data **data, char *str);
pid_t ft_fork(pid_t child, char *str);
void ft_wait(int pid);
void ft_unlink(char *str);
void    check_exec_cmd(char *cmd, char **env);
int ft_check_path_cmd(char *cmd);
char *ft_found_cmd (char *cmd, char **path);
char *fet_path(char **env);
void pars_cmd_1(char *cmd);
void pars_cmd_2(char **cmd_split, char **env);
void pars_cmd_3(char **cmd_split, char **env);
void ft_double_free (char **str);


#endif