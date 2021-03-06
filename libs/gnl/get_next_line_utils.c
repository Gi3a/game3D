

#include "get_next_line.h"

size_t	_len(char *str, int f)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (f == 1)
		while (str[i] && str[i] != '\n')
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

int		_return(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (_len((char *)s1, 0) + \
						_len((char *)s2, 0) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*_dup(char *str)
{
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	i = _len((char*)str, 1);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*_ndup(char *str)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	j = 0;
	i = _len(str, 1);
	if (!str[i] || !(new = (char*)malloc(sizeof(char) * \
					((_len(str, 0) - i) + 1))))
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}
