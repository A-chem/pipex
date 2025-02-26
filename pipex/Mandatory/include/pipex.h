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
void    check_exec_cmd(char *cmd, char **env);

#endif