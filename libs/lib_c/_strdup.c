
#include "lib.h"

char	*_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
		size++;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
