NAMEC		= client
NAMES		= server
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCSC		= client_bonus.c
SRCSS		= server_bonus.c

OBJSC		= $(SRCSC:.c=.o)
OBJSS		= $(SRCSS:.c=.o)


all: $(NAMEC) $(NAMES)

$(NAMEC): $(SRCSC)
	$(CC) $(SRCSC) -o $(NAMEC) $(CFLAGS)

$(NAMES): $(SRCSS)
	$(CC) $(SRCSS) -o $(NAMES) $(CFLAGS)

clean:
	$(RM) $(OBJSC) $(OBJSS) 

fclean: clean
	$(RM) $(NAMEC) $(NAMES) 

re: fclean all

.PHONY: all clean fclean re