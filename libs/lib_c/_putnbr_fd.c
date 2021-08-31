
#include "lib.h"

void	_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		_putchar_fd('-', fd);
		n = n * -1;
	}
	nbr = n;
	if (nbr < 10)
	{
		_putchar_fd(nbr + '0', fd);
	}
	else
	{
		_putnbr_fd(nbr / 10, fd);
		_putchar_fd(nbr % 10 + '0', fd);
	}
}
