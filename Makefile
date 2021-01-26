CC			= gcc -Wall -Wextra -Werror
RM			= rm -rf
NAME		= test
LIB			= libasm
NASM		= nasm
NFLAGS		= -f elf64

SRCS		= ft_strlen.s ft_strcmp.s

OBJS		= $(SRCS:.s=.o)

%.o			: %.s
			$(NASM) $(NFLAGS) $< -o $@

all			: $(LIB)

$(LIB)		: $(OBJS)
			@ar rcs $(LIB) $(OBJS)
			@$(CC) main.c $(LIB) -o $(NAME)

clean:
			@$(RM) $(OBJS) main.o

fclean		: clean
			@$(RM) $(NAME) $(LIB)

re			: fclean all

.PHONY		: all clean fclean re
