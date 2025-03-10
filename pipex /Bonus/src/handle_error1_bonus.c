/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:40:35 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/09 23:47:23 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	handle_errors(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		handle_errors("Error closing file descriptor\n");
}
