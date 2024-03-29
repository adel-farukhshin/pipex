/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:43:40 by bsarai            #+#    #+#             */
/*   Updated: 2022/03/10 10:43:41 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**path;
	char	**cmd;
	char	**env;
}	t_pipex;

void			get_path(t_pipex *pipex);

int				connect(t_pipex *pipex);
int				get_cmd(t_pipex *pipex);

void			free_pipex(t_pipex *pipex);
void			free_strs(char **strs);

char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strncopy(char *dst, const char *src, int n);
unsigned long	ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
void			ft_free_words(char **words);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
