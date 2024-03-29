/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:45:12 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/13 13:45:13 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdlib.h>
#include "ft_printf.h"
#include "pipex.h"

static void	err_cmd(t_pipex *pipex)
{
	write(2, "Command not found\n", 18);
	free_pipex(pipex);
	exit (1);
}

char	*add_cmd(char *path, char *cmd)
{
	char	*t_path;
	char	*tmp;
	char	**t_cmd;

	t_path = ft_strdup(path);
	tmp = ft_strjoin(t_path, "/");
	free(t_path);
	t_cmd = ft_split(cmd, ' ');
	t_path = ft_strjoin(tmp, t_cmd[0]);
	free(tmp);
	free_strs(t_cmd);
	return (t_path);
}

int	get_cmd(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	while (i < pipex->argc - 1)
	{
		while (pipex->path[j])
		{	
			tmp = add_cmd(pipex->path[j], pipex->argv[i]);
			if (!access(tmp, X_OK))
				pipex->cmd[i - 2] = tmp;
			else
				free(tmp);
			j++;
		}
		if (!pipex->cmd[i - 2])
			err_cmd(pipex);
		j = 0;
		i++;
	}
	free_strs(pipex->path);
	pipex->path = NULL;
	return (1);
}
