

#include "lib.h"

void	_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			_putchar_fd(s[i], fd);
			i++;
		}
	}
	return ;
}
