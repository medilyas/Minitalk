CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_S = server.c
SRC_C = client.c
SRC_S_BONUS = bonus/server_bonus.c
SRC_C_BONUS = bonus/client_bonus.c
PRINTF = ft_printf/printf.a
OBJ_S = ${SRC_S:%.c=%.o}
OBJ_C = ${SRC_C:%.c=%.o}
OBJ_S_BONUS = ${SRC_S_BONUS:%.c=%.o}
OBJ_C_BONUS = ${SRC_C_BONUS:%.c=%.o}
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

.c.o :
	${CC} ${CFLAGS} -c $< -o $@
all : printf ${CLIENT} ${SERVER}

${SERVER}: ${OBJ_S}
	${CC} ${PRINTF} ${OBJ_S} -o ${SERVER}
${CLIENT} : ${OBJ_C}
	${CC} ${PRINTF} ${OBJ_C} -o ${CLIENT}

bonus : printf ${SERVER_BONUS} ${CLIENT_BONUS}
${SERVER_BONUS}: ${OBJ_S_BONUS}
	${CC} ${PRINTF} ${OBJ_S_BONUS} -o ${SERVER_BONUS}
${CLIENT_BONUS} : ${OBJ_C_BONUS}
	${CC} ${PRINTF} ${OBJ_C_BONUS} -o ${CLIENT_BONUS}

printf :
	make -C ft_printf/

clean :
	make clean -C ft_printf/
	rm -f ${OBJ_C} ${OBJ_S} ${OBJ_C_BONUS} ${OBJ_S_BONUS}
fclean : clean
	rm -f ${PRINTF}
	rm -f ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}
re: fclean all

.PHONY: all clean fclean re bonus