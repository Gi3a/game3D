

#include "lib.h"

void	*_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (dst || src)
	{
		d = (unsigned char*)dst;
		s = (unsigned char*)src;
		while (n)
		{
			*d = *s;
			if (*d == (unsigned char)c)
				return ((void*)++d);
			d++;
			s++;
			n--;
		}
		return (NULL);
	}
	return (NULL);
}
