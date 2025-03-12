/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:27:45 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/12 17:54:14 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_first_cmd(t_data *data)
{
	data->fd_in = open(data ->av[1], O_RDONLY, 0644);
	if (data->fd_in == -1)
	{
		ft_close(data->fd[1]);
		perror (data->av[1]);
		exit (1);
	}
	if (dup2(data->fd_in, 0) == -1)
		handle_errors("Dup2 Failed\n");
	ft_close(data->fd_in);
}

static void	ft_last_cmd(t_data *data)
{
	if (data->flag == 1)
		data->fd_out = open(data->av[data->ac - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		data->fd_out = open(data->av[data->ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == -1)
		handle_errors("Error opening outfile");
	if (dup2(data->fd_out, 1) == -1)
		handle_errors("Dup2 Failed\n");
	ft_close(data->fd_out);
	check_exec_cmd(data->av[data->i], data->env);
}

void	ft_child_processes(t_data *data)
{
	ft_close(data->fd[0]);
	if (data->i == 2)
		ft_first_cmd(data);
	if ((data->flag == 1) && data->i == 3)
	{
		if (dup2(data->fd_in, 0) == -1)
			handle_errors("Dup2 Failed\n");
		ft_close(data->fd_in);
	}
	if (data->fd_save != -1 && dup2(data->fd_save, 0) == -1)
		handle_errors("Error");
	if(data->fd_save != -1)
		ft_close(data->fd_save);
	if (data->i == data->ac - 2)
		ft_last_cmd(data);
	if (dup2(data->fd[1], 1) == -1)
		handle_errors("Dup2 Failed\n");
	ft_close(data->fd[1]);
	check_exec_cmd(data->av[data->i], data->env);
}
