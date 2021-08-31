

#include "lib.h"

char	*_strchr(const char *s, int c)
{
	char	*ps;

	ps = (char*)s;
	while (*ps && *ps != (char)c)
		ps++;
	if (*ps == c)
		return (ps);
	return (0);
}
