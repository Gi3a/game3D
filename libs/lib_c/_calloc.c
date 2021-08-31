

#include "lib.h"

void	*_calloc(size_t count, size_t size)
{
	char *mem;

	mem = (void*)malloc(count * size);
	if (mem == NULL)
		return (NULL);
	_memset(mem, 0, count * size);
	return (mem);
}
