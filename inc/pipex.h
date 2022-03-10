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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:25:08 by bsarai            #+#    #+#             */
/*   Updated: 2021/11/14 18:25:10 by bsarai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**path;
}	t_pipex;

void			get_path(char **env);

int				connect(void);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strncopy(char *dst, const char *src, int n);
unsigned long	ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);

#endif
