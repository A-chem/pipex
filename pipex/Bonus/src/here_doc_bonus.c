/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:07:26 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/06 22:25:01 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_read_input(char **av, t_data *data)
{
	size_t	len_s;
	char	*str;
	char	*limited;

	limited = ft_strjoin(av[2], "\n");
	if (!limited)
		return ;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			free(limited);
			break ;
		}
		if (ft_strcmp(str, limited) == 0)
		{
			free(str);
			free(limited);
			break ;
		}
		len_s = ft_strlen(str);
		write(data->fd[1], str, len_s);
		free(str);
	}
}

void	ft_here_doc(char **av, t_data *data)
{
	int	child;

	ft_pipe(&data);
	child = ft_fork();
	if (child == 0)
	{
		ft_close(data->fd[0]);
		ft_read_input(av, data);
		ft_close(data->fd[1]);
	}
	ft_close(data->fd[1]);
	ft_dup2(data->fd[0], 0);
	ft_close(data->fd[0]);
	waitpid(child, NULL, 0);
}
