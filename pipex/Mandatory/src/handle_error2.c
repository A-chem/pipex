/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:24:25 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/05 15:25:25 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_wait(int pid)
{
	pid_t	terminated_pid;

	terminated_pid = waitpid(pid, NULL, 0);
	if (terminated_pid == -1)
		handle_errors ("waitpid failed");
}

void	ft_unlink(char *str)
{
	if (unlink(str) == -1)
		handle_errors("unlink failed");
}
