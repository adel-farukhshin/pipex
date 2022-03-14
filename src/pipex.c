/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:43:25 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/10 10:43:26 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdlib.h>
#include <time.h>

#include "ft_printf.h"
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int	fd;

	if (argc != 5)
	{
		write(2, "Error: ./pipex file1 cmd1 cmd2 file2\n", 37);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		perror("Error message");
		exit(-1);
	}
	close(fd);
		pipex = malloc(sizeof(t_pipex));
		if (pipex == NULL)
			return (-1);
		pipex->cmd = malloc(sizeof(char *) * 3);
		if (!pipex->cmd)
			return (-1);
		pipex->cmd[0] = NULL;
		pipex->cmd[1] = NULL;
		pipex->cmd[2] = NULL;
		pipex->argc = argc;
		pipex->argv = argv;
		pipex->env = env;
		get_path(pipex);
		get_cmd(pipex);
		connect(pipex);
		free_pipex(pipex);
		// sleep(100);
		// ft_free_words(pipex->path);
	
	
	return (0);
}
