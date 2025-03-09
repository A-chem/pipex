/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:52:45 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/06 13:53:55 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_wait(void)
{
	pid_t	terminated_pid;

	terminated_pid = wait(NULL);
	if (terminated_pid == -1)
	{
		ft_putstr("Error waiting");
		exit(1);
	}
}
