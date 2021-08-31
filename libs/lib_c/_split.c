

#include "lib.h"

static int		_get_count_words(char *str, char c)
{
	int		i;
	int		j;
	int		words;

	i = 0;
	j = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			j++;
		if (str[i] == c || str[i + 1] == '\0')
		{
			if (j > 0)
				words++;
			j = 0;
		}
		i++;
	}
	return (words);
}

static char		**_alloc_split(int size)
{
	char	**new;

	new = (char**)malloc(sizeof(new) * (size + 1));
	if (new == NULL)
		return (NULL);
	return (new);
}

static void		*_free_split(char **new, int j)
{
	while (j)
	{
		free(new[j]);
		j--;
	}
	free(new);
	return (NULL);
}

static char		**_set_word(char **new, char *str, int size, char c)
{
	int		i;
	int		j;
	int		start;
	int		words;

	i = 0;
	j = 0;
	start = 0;
	words = 0;
	while (str[i] != '\0' && size + 1 > words)
	{
		j = (str[i] != c) ? j + 1 : j;
		if (str[i] != c && str[i - 1] == c)
			start = i;
		if (str[i] == c || str[i + 1] == '\0')
		{
			if (j > 0)
				if (!(new[words++] = _substr(str, start, j)))
					return (_free_split(new, j));
			j = 0;
		}
		i++;
	}
	new[words] = NULL;
	return (new);
}

char			**_split(char const *s, char c)
{
	int		size;
	char	**new;

	if (!s)
		return (NULL);
	size = _get_count_words((char*)s, c);
	if ((new = _alloc_split(size)) == NULL)
		return (NULL);
	if ((new = _set_word(new, (char*)s, size, c)) == NULL)
		return (NULL);
	return (new);
}
