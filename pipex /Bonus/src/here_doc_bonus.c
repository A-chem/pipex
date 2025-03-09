/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:07:26 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/09 23:19:57 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_read_input(char **av, t_data *data)
{
	char	*str;
	char	*limited;

	limited = ft_strjoin(av[2], "\n");
	if (!limited)
		return ;
	while (1)
	{
		write (1, "> ", 3);
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
		write(data->fd[1], str, ft_strlen(str));
		free(str);
	}
}

int	ft_here_doc(t_data *data)	
{
	pipe(data->fd);
	ft_read_input(data->av, data);
	close(data->fd[1]);
	return (data->fd[0]);
}