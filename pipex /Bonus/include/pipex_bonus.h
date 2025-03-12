/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:48:17 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/12 17:54:39 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "get_next_line_bonus.h"

typedef struct s_data
{
	int		fd[2];
	int		fd_in;
	int		fd_out;
	int		i;
	char	**av;
	char	**env;
	int		ac;
	int		fd_save;
	int		flag;
}			t_data;

void	ft_putstr(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
void	ft_close(int fd);
int		ft_here_doc(t_data *data);
void	ft_child_proc(t_data *data);
void	check_exec_cmd(char *cmd, char **env);
int		ft_check_path_cmd(char *cmd);
char	*ft_found_cmd(char *cmd, char **path);
char	*fet_path(char **env);
void	pars_cmd_1(char *cmd);
void	pars_cmd_2(char **cmd_split, char **env);
void	pars_cmd_3(char **cmd_split, char **env);
void	handle_errors(char *str);
void	ft_double_free(char **str);
void	ft_child_processes(t_data *data);

#endif
