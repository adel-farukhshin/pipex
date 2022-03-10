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
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	// int	fd[2];

	if (argc > 1) // == 5)
	{
		pipex = malloc(sizeof(pipex));
		if (pipex == NULL)
			return (1);
		(void) argv;
		get_path(env, pipex);
		connect();
	}
	ft_free_words(pipex->path);
	return (0);
}
