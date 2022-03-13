/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:41 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/10 14:40:42 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "pipex.h"

void	get_path(t_pipex *pipex)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	// ft_printf("*env is: %s", *env);
	while (pipex->env[i])
	{
		if (ft_strstr(pipex->env[i], "PATH"))
			str = ft_strstr(pipex->env[i], "PATH");
		i++;
	}
	tmp = ft_strdup(str);
	// ft_printf("%s\n", tmp);
	pipex->path = ft_split(tmp + 5, ':');
	free(tmp);
	i = 0;
	// while (pipex->path[i])
	// {
	// 	ft_printf("%s\n", pipex->path[i]);
	// 	i++;
	// }

}
