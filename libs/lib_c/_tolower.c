

int	_tolower(int c)
{
	if (c)
	{
		if (c >= 'A' && c <= 'Z')
		{
			c = c - 'A' + 'a';
		}
	}
	return (c);
}
