

#include "lib.h"

void	*_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dst;
	s = src;
	if (d == NULL && s == NULL)
		return (NULL);
	if ((uintptr_t)s < (uintptr_t)d)
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len--)
			*d-- = *s--;
		return (dst);
	}
	if ((uintptr_t)s > (uintptr_t)d)
	{
		while (i++ != len)
			*d++ = *s++;
		return (dst);
	}
	return (dst);
}
