

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t		_len(char *str, int f);
char		*_dup(char *str);
char		*_join(char *s1, char *s2);
int			_return(char *str);
char		*_ndup(char *str);
int			get_next_line(int fd, char **line);

#endif
