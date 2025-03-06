/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:27:45 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/06 13:33:13 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_process(char *cmd, char **env, bool cdt, t_data *data, char **av)
{
	int	child;

	ft_pipe(&data);
	child = ft_fork();
	if (child == 0)
	{
		ft_close(data->fd[0]);
		if (data->i == 2)
		{
			data->fd_in = open(av[1], O_RDONLY);
			if (data->fd_in == -1)
			{
				perror(av [1]);
				exit(1);
			}
			ft_dup2(data->fd_in, 0);
			ft_close(data->fd_in);
		}
		if (cdt)
		{
			ft_dup2(data->fd_out, 1);
			ft_close(data->fd_out);
		}
		else
		{
			ft_dup2(data->fd[1], 1);
			ft_close(data->fd[1]);
		}
		check_exec_cmd(cmd, env);
	}
	else
	{
		ft_close(data->fd[1]);
		ft_dup2(data->fd[0], 0);
		ft_close(data->fd[0]);
	}
}
