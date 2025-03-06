/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:01:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/06 13:07:13 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_open(int flag, int ac, char **av, t_data *data)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			exit(1);
		ft_here_doc(av, data);
		data->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (data->fd_out == -1)
			handle_errors("Error Opening File");
		flag++;
	}
	else
	{
		data->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (data->fd_out == -1)
			handle_errors("Error Opening File");
	}
	return (flag);
}

void	pipex(int ac, char **av, char **env, t_data *data)
{
	data->i = ft_open(1, ac, av, data);
	while (++data->i < ac - 1)
		ft_process(av[data->i], env, (data->i + 1 == ac - 1), data, av);
	ft_close(data->fd_out);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		handle_errors("Error: Invalid number of arguments\n");
	if (!*env || !env)
		handle_errors("Error: Invalid environment\n");
	pipex(ac, av, env, &data);
}
