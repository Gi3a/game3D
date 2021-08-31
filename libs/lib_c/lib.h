

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					_tolower(int c);
int					_toupper(int c);
int					_isprint(int c);
int					_isascii(int c);
int					_isalnum(int c);
int					_isalpha(int c);
int					_isdigit(int c);
int					_atoi(const char *str);
void				*_memset(void *b, int c, size_t len);
void				_bzero(void *s, size_t n);
void				*_memcpy(void *dst, const void *src, size_t n);
int					_strncmp(const char *s1,
		const char *s2, size_t n);
char				*_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*_strchr(const char *s, int c);
char				*_strrchr(const char *s, int c);
size_t				_strlcat(char *dst,
		const char *src, size_t dstsize);
size_t				_strlcpy(char *dst,
		const char *src, size_t dstsize);
size_t				_strlen(const char *s);
int					_memcmp(const void *s1,
		const void *s2, size_t n);
void				*_memchr(const void *s, int c, size_t n);
void				*_memmove(void *dst,
		const void *src, size_t len);
void				*_memccpy(void *dst,
		const void *src, int c, size_t n);
void				*_calloc(size_t count, size_t size);
char				*_strdup(const char *s1);
char				*_substr(char const *s,
		unsigned int start, size_t len);
char				*_strjoin(char const *s1, char const *s2);
char				*_strtrim(char const *s1, char const *set);
char				*_itoa(int n);
char				*_strmapi(char const *s,
		char (*f)(unsigned int, char));
char				**_split(char const *s, char c);
void				_putchar_fd(char c, int fd);
void				_putstr_fd(char *s, int fd);
void				_putendl_fd(char *s, int fd);
void				_putnbr_fd(int n, int fd);
t_list				*_lstnew(void *content);
void				_lstadd_front(t_list **lst, t_list *new);
int					_lstsize(t_list *lst);
t_list				*_lstlast(t_list *lst);
void				_lstadd_back(t_list **lst, t_list *new);
void				_lstdelone(t_list *lst,
		void (*del)(void*));
void				_lstclear(t_list **lst,
		void (*del)(void*));
void				_lstiter(t_list *lst,
		void (*f)(void *));
t_list				*_lstmap(t_list *lst,
		void *(*f)(void *), void (*del)(void *));
#endif
