SRCS = 	push_swap.c \
		Utils/join_and_others.c \
		Utils/ft_split.c \
		Utils/atoi_and_lst.c \
		get_args.c \
		Operations/operations_s.c \
		Operations/operations_p.c \
		Operations/operations_r.c \
		Operations/operations_rr.c \
		begin_and_lil_sort.c \
		big_sort.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

%.o: %.c push_swap.h
	$(CC) ${CFLAGS} -c -o $@ $<

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re