

#include "lib.h"

int	_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ps1;
	const unsigned char *ps2;

	ps1 = s1;
	ps2 = s2;
	while (n)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
		n--;
	}
	return (0);
}
