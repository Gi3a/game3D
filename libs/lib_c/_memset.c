

#include "lib.h"

void	*_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = b;
	c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*d = c;
		d++;
		i++;
	}
	return (b);
}
