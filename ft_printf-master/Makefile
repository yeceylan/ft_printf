SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar rc #r yenıden olusturma , c mesajı gizler 
RM		= rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re