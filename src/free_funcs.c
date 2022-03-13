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

void	free_pipex(t_pipex *pipex)
{
	if (pipex->path)
		ft_free_words(pipex->path);
	if (pipex->cmd)
		ft_free_words(pipex->cmd);
	free (pipex);
}
