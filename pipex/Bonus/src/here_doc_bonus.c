#include "../include/pipex_bonus.h"


void ft_read_input(char **av, t_data *data)
{
    size_t	len_s;
	char	*str;
	char	*limited;

	limited = ft_strjoin(av[2], "\n");
	if (!limited)
		exit(1);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			exit(1);
		if (ft_strcmp(str, limited) == 0)
		{
			free(str);
			free(limited);
			exit(0);
		}
		len_s = ft_strlen(str);
		write(data->fd[1], str, len_s);
		free(str);
	}
}

void ft_here_doc(char **av, t_data *data)
{
    int child = 0;

    ft_pipe(&data, "Pipe Failed");
    child = ft_fork(child, "Fork  Failed");
    if(child == 0)
    {
        ft_close(data->fd[0]);
		ft_read_input(av, data);
		ft_close(data->fd[1]);
    }
    else
        {
            ft_close(data->fd[1]);
            ft_dup2(data->fd[0], 0, "Dup Failed");
            ft_close(data->fd[0]);
			waitpid(child, NULL, 0);
        }
		
}