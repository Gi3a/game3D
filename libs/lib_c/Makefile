NAME = lib.a
SRCS = _atoi.c _bzero.c _calloc.c _isalnum.c\
		_isalpha.c _isascii.c _isdigit.c _isprint.c\
		_itoa.c _memccpy.c _memchr.c _memcmp.c\
		_memcpy.c _memmove.c _memset.c _split.c\
		_putchar_fd.c _putendl_fd.c _putnbr_fd.c\
		_putstr_fd.c _strchr.c _strdup.c _strjoin.c\
		_strlcat.c _strlcpy.c _strlen.c _strmapi.c\
		_strncmp.c _strnstr.c _strrchr.c _strtrim.c\
		_substr.c _tolower.c _toupper.c
OBJS = $(SRCS:.c=.o)

BONUS = _lstnew.c _lstadd_front.c _lstsize.c\
		_lstlast.c _lstadd_back.c _lstdelone.c\
		_lstclear.c _lstiter.c _lstmap.c
O_BONUS = $(BONUS:.c=.o)

INC = lib.h

CC      = gcc
AR      = ar rc
RANL    = ranlib
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -I ${INC} -c $< -o ${<:.c=.o}
$(NAME):	${OBJS} ${INC}
			${AR} ${NAME} ${OBJS}
			${RANL} ${NAME}
all:		${NAME}
bonus:		${OBJS} ${O_BONUS}
			${AR} ${NAME} ${O_BONUS}
			${RANL} ${NAME}
clean:
			${RM} ${OBJS} ${O_BONUS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re bonus
