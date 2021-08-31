

int	_toupper(int c)
{
	if (c)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = c - 'a' + 'A';
		}
	}
	return (c);
}
