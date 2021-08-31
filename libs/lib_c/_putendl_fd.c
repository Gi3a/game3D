

#include "lib.h"

void	_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			_putchar_fd(s[i], fd);
			i++;
		}
		_putchar_fd('\n', fd);
	}
	return ;
}
