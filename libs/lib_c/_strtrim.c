

#include "lib.h"

static int	_leright(char const *s1, char const *set, int r)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (s1[i] && i == t)
	{
		r = 0;
		while (s1[i] != set[r] && set[r])
			r++;
		if (set[r] != '\0')
			t++;
		i++;
	}
	return (t);
}

char		*_strtrim(char const *s1, char const *set)
{
	int		r;
	int		e;
	int		len;
	int		h;

	e = 0;
	r = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	h = _leright(s1, set, r);
	len = (int)_strlen(s1) - 1;
	e = len;
	while (&s1[len] != s1 && len == e)
	{
		r = 0;
		while (s1[len] != set[r] && set[r])
			r++;
		if (set[r] != '\0')
			e--;
		len--;
	}
	return (_substr(s1, h, (e - h + 1)));
}
