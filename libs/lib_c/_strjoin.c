

#include "lib.h"

char	*_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		total;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	total = _strlen(s1) + _strlen(s2);
	new = (char*)malloc(sizeof(char) * (total) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
