/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:01:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/09 23:47:05 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_process(t_data *data)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		handle_errors("Pipe Failed\n");
	pid = fork();
	if (pid == -1)
		handle_errors("Fork  Failed\n");
	if (pid == 0)
		ft_child_processes(data);
	close(data->fd_save);
	data->fd_save = dup(data->fd[0]);
	if (data->fd_save == -1)
		handle_errors("Error\n");
	close(data->fd[0]);
	close(data->fd[1]);
}

static void	pipex(t_data *data)
{
	data->i = 2;
	data->fd_save = -1;
	if (data->flag == 1)
		data->i = 3;
	while (data->i <= data->ac - 2)
	{
		ft_process(data);
		data->i++;
	}
	close(data->fd_save);
	close(data->fd_in);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	data.av = av;
	data.env = env;
	if (ac < 5)
		handle_errors("Error: Missing file or command arguments.");
	if (!*env || !env)
		handle_errors("Error empty environment");
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data.ac = ac;
		data.flag = 1;
		data.fd_in = ft_here_doc(&data);
	}
	else if (ac >= 5)
	{
		data.ac = ac;
		data.flag = 0;
	}
	pipex(&data);
	return (0);
}
