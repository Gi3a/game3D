

#include "lib.h"

void	*_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (dst || src)
	{
		while (n)
		{
			*d = *s;
			++d;
			++s;
			n--;
		}
		return (dst);
	}
	return (NULL);
}
