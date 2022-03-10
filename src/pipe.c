/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:29:38 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/10 14:29:39 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdlib.h>
#include <time.h>

#include "ft_printf.h"
#include "pipex.h"

int	check_cmd(t_pipex *pipex)
{
	int		i;
	int		j;
	int		res;
	char	*tmp;
	char	*tmp0;

	i = 2;
	j = 0;
	while (i < pipex->argc - 1)
	{
		while (pipex->path[j])
		{
			tmp0 = ft_strjoin(pipex->path[j], "/"); 
			tmp = ft_strjoin(tmp0, pipex->argv[i]);
			free(tmp0);
			res = access(tmp, X_OK);
			ft_printf("Trying to access %s; __ A_code is %d\n", tmp, res);
			if (!res)
				pipex->cmd[i - 2] = tmp;
			else
				free(tmp);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1); // handle errors
}

int	connect(t_pipex *pipex)
{
	int	fd[2];

	ft_printf("%s\n", pipex->path[0]);
	int	i;
	
	i = check_cmd(pipex);
	// if (i == -1)
	// {
	// 	ft_printf("Command not found\n");
	// 	return (6);
	// }

	ft_printf("cmd1: %s\ncmd2: %s\n", pipex->cmd[0], pipex->cmd[1]);
	// i = access("bin/cat", X_OK);
	// ft_printf("Access code is %d\n", i);

	if (pipe(fd) == -1)
	{
		return (1);
	}


	int	pid1 = fork();
	
	if (pid1 < 0)
	{
		return (2);
	}
	if (pid1 == 0)
	{ 
		int	file = open(pipex->argv[1], O_RDONLY);
		if (file == -1)
			return (4);
		dup2(file, STDIN_FILENO);
		close(file);
		// ft_printf("In child 1\n");
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execlp("cat", "cat", NULL);
		// execlp("ping", "ping", "-c", "1", "google.com", NULL);
	}

	int	pid2 = fork();
	if (pid2 < 0)
	{
		return (3);
	}
	if (pid2 == 0)
	{
		int	file = open(pipex->argv[pipex->argc - 1]
				, O_WRONLY | O_CREAT, 0777);
		// ft_printf("In child 1\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("/usr/bin/grep", "/usr/bin/grep", "hello", NULL);
	}
	// ft_printf("Hi\n");

	close(fd[0]); 
	close(fd[1]); 
	waitpid(pid1, NULL, 0);
	waitpid(pid2 , NULL, 0);
	return (0);
}