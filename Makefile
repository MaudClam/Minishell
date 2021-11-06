NAME			=	minishell

SRCS			=   srcs/main.c \
					srcs/lexer.c \
					srcs/lexer1.c \
					srcs/lexer2.c \
					srcs/parser.c \
					srcs/parser1.c \
					srcs/parser2.c \
					srcs/executer.c \
					srcs/utils.c \
					srcs/utils1.c \
					srcs/utils2.c

LIBFT			=	${LIBFTDIR}libft.a
LIBFTDIR		=	libft/

RLINE_DIR_LIB	=	/usr/local/Cellar/readline/8.1.1/lib
RLINE_DIR_INC	=	/usr/local/Cellar/readline/8.1.1/include

OBJS			=	${SRCS:.c=.o}

INCLUDE			=	include/

CFLAGS			=	-Wall -Wextra -Werror

GCC				=	gcc

CLEAN			=	rm -f

.c.o:
				${GCC} ${CFLAGS} -I${LIBFTDIR} -Iinclude -I${RLINE_DIR_INC} \
				-c $< -o ${<:.c=.o}

${NAME}:		${LIBFT} ${OBJS} include
				${GCC} ${OBJS} \
				-L${LIBFTDIR} -lft \
				-I${LIBFTDIR} -Iinclude \
				-I${RLINE_DIR_INC} \
				-L${LIBFTDIR} -lft \
				-L${RLINE_DIR_LIB} -lreadline \
				-o ${NAME}

${LIBFT}:
				make -C ${LIBFTDIR} libft.a

all:			${NAME}

clean:
				${CLEAN} ${OBJS}
				make -C ${LIBFTDIR} clean

fclean:			clean
				${CLEAN} ${NAME}
				make -C ${LIBFTDIR} fclean

re:				fclean all

.PHONY:			all clean fclean re libft
