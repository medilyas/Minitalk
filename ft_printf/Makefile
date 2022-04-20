RS = resources/

UT = utils/

SRCS = ft_printf.c ${RS}ft_calloc.c ${RS}ft_atoi.c \
	${RS}ft_itoa.c ${RS}ft_utoa.c ${RS}ft_strlen.c \
	${UT}type_render_csdi.c ${UT}type_render_uxp.c

NAME = printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

OBJS = ${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@
	${AR} ${NAME} $@

all : ${NAME}

${NAME} : ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : re fclean clean all
