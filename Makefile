NAME = pipex
BONUS = pipex_bonus
CFLAGS = -Wall -Wextra -Werror
CC = CC
RM = rm -f
SRC = mand/child_process.c mand/free.c mand/ft_exit.c mand/ft_strjoin.c mand/ft_split.c mand/ft_strlen.c mand/get_path.c \
	mand/parent_process.c mand/main.c mand/ft_strncmp.c
SRCB = bonus/child_process.c bonus/free.c bonus/ft_exit.c bonus/ft_strjoin.c bonus/ft_split.c \
	bonus/ft_strlen.c bonus/get_path.c bonus/ft_strncmp.c bonus/ft_execve.c bonus/main.c \
	bonus/ft_open.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/here_doc.c

OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus : ${BONUS}

${BONUS} : ${OBJB}
	${CC} ${CFLAGS} ${OBJB} -o ${BONUS}

clean :
	${RM} ${OBJ} ${OBJB}

fclean : clean
	${RM} ${NAME} ${BONUS}

re : fclean all