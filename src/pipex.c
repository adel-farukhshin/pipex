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
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdlib.h>
#include <time.h>

#include "ft_printf.h"

int	main()
{
	int	fd[2];

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
		int	file = open("in", O_RDONLY);
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
		int	file = open("out", O_CREAT | O_WRONLY, 0777);
		// ft_printf("In child 1\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "", NULL);
	}
	// ft_printf("Hi\n");

	close(fd[0]); 
	close(fd[1]); 
	waitpid(pid1, NULL, 0);
	waitpid(pid2 , NULL, 0);
	
	return (0);
}
