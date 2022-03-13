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

static void	is_tofree(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd[i] != NULL)
	{
		// ft_printf("cmd is %s\n", pipex->cmd[i]);
		i++;
	}
	// ft_printf("i in is_tofree is equal to %d\n", i);
	if (i != pipex->argc - 3)
	{
		// ft_printf("in if is_tofree i %d, argc %d\n", i, pipex->argc);
		free_pipex(pipex);
		exit (1);
	}
	else
	{
		// ft_printf("in else is_tofree\n");
		free_strs(pipex->path);
		pipex->path = NULL;
	}
}

char	*get_cmd(char *path, char *cmd)
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

int	check_cmd(t_pipex *pipex)
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
			tmp = get_cmd(pipex->path[j], pipex->argv[i]);
			// ft_printf("Trying to access %s; __ A_code is %d; i is %d\n", tmp, res, i);
			if (!access(tmp, X_OK))
				pipex->cmd[i - 2] = tmp;
			else
				free(tmp);
			j++;
		}
		j = 0;
		i++;
	}
	is_tofree(pipex);
	return (-1); // handle errors
}