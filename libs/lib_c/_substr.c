

#include "lib.h"

char	*_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	char			*new;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start >= _strlen(s))
	{
		new = (char*)malloc(sizeof(char) * 1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	while (i != start)
		i++;
	new = (char*)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (s[i] && len--)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
