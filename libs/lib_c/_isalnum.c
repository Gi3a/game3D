

#include "lib.h"

int	_isalnum(int c)
{
	if (_isdigit(c) || _isalpha(c))
		return (1);
	return (0);
}
