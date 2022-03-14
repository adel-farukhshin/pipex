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
#include <sys/wait.h>
#include <fcntl.h>
#include "ft_printf.h"
#include "pipex.h"

#include <errno.h>
#include <stdio.h>

void	err_process(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	perror("Error mesage");
}

int	child1(int fd[2], t_pipex *pipex)
{
	int		file;	
	int		pid1;
	char	**l_argv;
	
	pid1 = fork();
	if (pid1 < 0)
	{
		err_process(fd);
		return (-1);
	}
	if (pid1 == 0)
	{ 
		file = open(pipex->argv[1], O_RDONLY);
		if (file == -1)
		{
			err_process(fd);
			return (-1);
		}
		dup2(file, STDIN_FILENO);
		close(file);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		l_argv = ft_split(pipex->argv[2], ' ');
		execve(pipex->cmd[0], l_argv, pipex->env);
	}
	return(pid1);
}

int	child2(int fd[2], t_pipex *pipex)
{
	char	**l_argv;
	int		file;
	int		pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		err_process(fd);
		return (-1);
	}
	if (pid2 == 0)
	{
		unlink(pipex->argv[pipex->argc - 1]);
		file = open(pipex->argv[pipex->argc - 1]
				, O_WRONLY | O_CREAT, 0777);
		if (file < 0)
		{
			err_process(fd);
			return (-1);
		}
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		l_argv = ft_split(pipex->argv[3], ' ');
		execve(pipex->cmd[1], l_argv, pipex->env);
	}
	return (pid2);
}

int	connect(t_pipex *pipex)
{
	int		fd[2];
	int 	pid1;
	int		pid2;

	if (pipe(fd) == -1)
	{
		perror("Error mesage");
		return (-1);
	}
	pid1 = child1(fd, pipex);
	pid2 = child2(fd, pipex);
	if ( pid1 < 0 || pid2 < 0)
	{
		err_process(fd);
		return (-1);
	}
	close(fd[0]); 
	close(fd[1]); 
	// sleep(100);
	waitpid(pid1, NULL, 0);
	waitpid(pid2 , NULL, 0);
	return (0);
}
