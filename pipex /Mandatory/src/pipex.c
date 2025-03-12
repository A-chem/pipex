/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:15:58 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/12 14:42:17 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	process_2(char **av, char **env, t_data *data)
{
	ft_close(data->fd[1]);
	if (pars_cmd_1(av[3]) == -1)
		return (ft_close(data->fd[0]), exit(1));
	data->fd_save[0] = dup(0);
	data->fd_save[1] = dup(1);
	data->fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_out == -1)
	{
		perror(av[4]);
		ft_close(data->fd[0]);
		exit (1);
	}
	ft_dup2(data->fd[0], 0, data->fd_out);
	ft_close(data->fd[0]);
	ft_dup2(data->fd_out, 1, data->fd[0]);
	ft_close(data->fd_out);
	if (check_exec_cmd(av[3], env) == -1)
	{
		dup2(data->fd_save[0], 0);
		dup2(data->fd_save[1], 1);
		ft_close(data->fd_save[0]);
		ft_close(data->fd_save[1]);
		exit (1);
	}
}

static void	process_1(char **av, char **env, t_data *data)
{
	ft_close(data->fd[0]);
	if (pars_cmd_1(av[2]) == -1)
		return (ft_close(data->fd[1]), exit(1));
	data->fd_save[0] = dup(0);
	data->fd_save[1] = dup(1);
	data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in == -1)
	{
		perror(av[1]);
		ft_close(data->fd[1]);
		exit (1);
	}
	ft_dup2(data->fd_in, 0, data->fd[1]);
	ft_close(data->fd_in);
	ft_dup2(data->fd[1], 1, data->fd_in);
	ft_close(data->fd[1]);
	if (check_exec_cmd(av[2], env) == -1)
	{
		dup2(data->fd_save[0], 0);
		dup2(data->fd_save[1], 1);
		ft_close(data->fd_save[0]);
		ft_close(data->fd_save[1]);
		exit (1);
	}
}

static void	pipex(char **av, char **env, t_data *data)
{
	pid_t	child_1;
	pid_t	child_2;

	if (pipe(data->fd) == -1)
		handle_errors("Pipe Failed\n");
	child_1 = ft_fork(data);
	if (child_1 == 0)
		process_1(av, env, data);
	child_2 = ft_fork(data);
	if (child_2 == 0)
		process_2(av, env, data);
	ft_close(data->fd[1]);
	ft_close(data->fd[0]);
	ft_wait(child_1, data);
	ft_wait(child_2, data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		handle_errors("Error: Invalid number of arguments\n");
	if (!*env || !env)
		handle_errors("Error: Invalid environment\n");
	pipex(av, env, &data);
	if (WIFEXITED(data.status))
		return (WEXITSTATUS(data.status));
	return (128 + WTERMSIG(data.status));
}
