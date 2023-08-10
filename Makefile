NAME_S = server
NAME_C = client
NAME_BS = server_bonus
NAME_BC = client_bonus

CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c
SRCS_BS = server_bonus.c
SRCS_BC = client_bonus.c
SRCS = ft_printf.c

OBJS_SRCS = $(SRCS:.c=.o)
OBJS_S = $(SRCS_S:.c=.o) $(OBJS_SRCS)
OBJS_C = $(SRCS_C:.c=.o) $(OBJS_SRCS)
OBJS_BS = $(SRCS_BS:.c=.o) $(OBJS_SRCS)
OBJS_BC = $(SRCS_BC:.c=.o) $(OBJS_SRCS)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	gcc $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	gcc $(CFLAGS) $(OBJS_C) -o ${NAME_C}


bonus: $(NAME_BS) $(NAME_BC)

$(NAME_BS): $(OBJS_BS)
	gcc $(CFLAGS) $(OBJS_BS) -o $(NAME_BS)

$(NAME_BC): $(OBJS_BC)
	gcc $(CFLAGS) $(OBJS_BC) -o $(NAME_BC)

clean:
	rm -rf $(OBJS_SRCS) $(OBJS_S) $(OBJS_C) $(OBJS_BS) $(OBJS_BC)

fclean: clean
	rm -rf $(NAME_S) $(NAME_C) $(NAME_BS) $(NAME_BC)

re: fclean all

.PHONY: all clean fclean re