NAME = pipex
CFLAGS = -Wall -Wextra -Werror
CC = CC
RM = rm -f
ƒ=
SRC = mand/child_process.c mand/free.c mand/ft_exit.c mand/ft_strjoin.c mand/ft_split.c mand/ft_strlen.c mand/get_path.c \
	mand/parent_process.c mand/main.c mand/ft_strncmp.c
SRCB = pipex_bonus/child_process.c pipex_bonus/free.c pipex_bonus/ft_exit.c pipex_bonus/ft_strjoin.c pipex_bonus/ft_split.c \
	pipex_bonus/ft_strlen.c pipex_bonus/get_path.c pipex_bonus/ft_strncmp.c pipex_bonus/ft_execve.c pipex_bonus/here_doc.c pipex_bonus/main.c \
	pipex_bonus/ft_open.c

OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}

all : ${NAME}

# ${NAME} : ${OBJ}

# 	${CC} ${CFLAGS} ${OBJ} -o ${NAME}
${OBJ} : %.o : %.c
	${CC} ${CFLAGS} -c -o $@ $<

${NAME} : ${OBJ}
	${CC} ${CFLAGS} $^ -o ${NAME}
clean :
	${RM} ${OBJ} ${OBJB}

fclean : clean
	${RM} ${NAME}

bonus : ${OBJB}
	${CC} ${CFLAGS} $^ -o ${NAME}

re : fclean all