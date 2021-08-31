
#include "lib.h"

void	_bzero(void *s, size_t n)
{
	char *str;

	str = s;
	while (n)
	{
		*str = '\0';
		++str;
		n--;
	}
}
