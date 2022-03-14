
#include <stdlib.h>
#include "pipex.h"
#include "ft_printf.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	tmp = (char *) s1;
	while (*tmp)
		ret[i++] = *tmp++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	char			*str;

	if (!s1 || !s2)
		return ((char *) s1);
	i = ft_strlen(s1);
	i += ft_strlen(s2);
	str = malloc(i + 1);
	if (!str)
		return (str);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	a;

	a = 0;
	while (*s)
	{
		a++;
		s++;
	}
	return (a);
}


char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	nlen;
	size_t	i;
	size_t	j;

	h = (char *) haystack;
	nlen = (size_t) ft_strlen(needle);
	if (!nlen)
		return (h);
	if (ft_strlen(haystack) < nlen)
		return (NULL);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			j++;
		if (j == nlen)
			return (&h[i]);
		i++;
	}
	return (NULL);
}