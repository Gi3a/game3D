

#include "lib.h"

char	*_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * _strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
