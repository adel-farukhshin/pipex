/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:19:09 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/13 14:19:10 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "pipex.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while(strs[i])
		{
			ft_printf("%s\n", strs[i]);
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->path)
		free_strs(pipex->path);
	if (pipex->cmd)
		free_strs(pipex->cmd);
	free (pipex);
}
