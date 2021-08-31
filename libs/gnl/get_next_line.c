

#include "get_next_line.h"

char	*_read(int fd, char *str, char *buf)
{
	int res;

	res = 1;
	while (res != 0 && !_return(str))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return ((char*)-1);
		}
		buf[res] = '\0';
		str = _join(str, buf);
	}
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		*buf;
	static char	*str;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	str = _read(fd, str, buf);
	if (str == (char*)-1)
		return (-1);
	*line = _dup(str);
	str = _ndup(str);
	if (!str)
	{
		free(str);
		return (0);
	}
	return (1);
}
