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


int	connect(t_pipex *pipex)
{
	int	fd[2];

	ft_printf("cmd1: %s\ncmd2: %s\n", pipex->cmd[0], pipex->cmd[1]);

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
		execlp("/bin/cat", "/bin/cat", NULL);
		// execlp(pipex->cmd[0], pipex->cmd[0], NULL);
		// execlp("ping", "ping", "-c", "1", "google.com", NULL);
	}
	// ft_printf("before second fork\n");
	int	pid2 = fork();
	if (pid2 < 0)
	{
		return (3);
	}
	if (pid2 == 0)
	{
		int	file = open(pipex->argv[pipex->argc - 1]
				, O_WRONLY | O_CREAT, 0777);
		// ft_printf("In child 2\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("/usr/bin/grep", "/usr/bin/grep", "hello", NULL);
		// execlp(pipex->cmd[1], pipex->cmd[1], "hello", NULL);
	}
	// ft_printf("after second fork\n");

	close(fd[0]); 
	close(fd[1]); 
	waitpid(pid1, NULL, 0);
	waitpid(pid2 , NULL, 0);
	return (0);
}