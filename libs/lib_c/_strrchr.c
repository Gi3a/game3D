

#include "lib.h"

char	*_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != 0 && s[i] != (char)c)
		i--;
	if ((char)c == s[i])
		return ((char*)&s[i]);
	return (0);
}
