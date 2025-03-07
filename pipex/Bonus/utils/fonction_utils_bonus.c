/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:05:48 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/06 22:16:22 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_check_path_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	pars_cmd_1(char *cmd)
{
	if ((cmd[0] == ' ' || cmd[ft_strlen(cmd) - 1] == ' ' || cmd[0] == '.' )
		&& ft_check_path_cmd(cmd) == 0)
	{
		ft_putstr(cmd);
		ft_putstr(": Command not found\n");
		exit(1);
	}
}

void	pars_cmd_2(char **cmd_split, char **env)
{
	if (access(cmd_split[0], F_OK) == -1)
	{
		perror(cmd_split[0]);
		ft_double_free (cmd_split);
		exit(1);
	}
	if (access(cmd_split[0], X_OK) == -1)
	{
		ft_putstr(cmd_split[0]);
		ft_putstr(": Permission Denied");
		ft_double_free (cmd_split);
		exit(1);
	}
	if (execve(cmd_split[0], cmd_split, env) == -1)
	{
		ft_double_free (cmd_split);
		handle_errors("Execve Failed");
	}
}

void	pars_cmd_3(char **cmd_split, char **env)
{
	char	**path;
	char	*path_cmd;

	path = ft_split(fet_path(env), ':');
	if (!path)
		return (ft_double_free (cmd_split), handle_errors("Error"));
	path_cmd = ft_found_cmd(cmd_split[0], path);
	if (!path_cmd)
	{
		ft_putstr(cmd_split[0]);
		ft_putstr(": Command not found");
		return (ft_double_free (cmd_split),
			ft_double_free(path), handle_errors("\n"));
	}
	if (execve(path_cmd, cmd_split, env) == -1)
		return (ft_double_free (cmd_split), ft_double_free(path),
			free(path_cmd), handle_errors("Execve Failed"));
}

void	ft_double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
