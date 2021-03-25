CC			= gcc -Wall -Wextra -Werror
RM			= rm -rf
NAME		= test
LIB			= libasm.a
NASM		= nasm
NFLAGS		= -f elf64

SRCS		= $(addprefix sources/, ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s\
			ft_read.s ft_strdup.s ft_list_size_bonus.s)

OBJS		= $(SRCS:.s=.o)

%.o			: %.s
			@$(NASM) $(NFLAGS) $< -o $@

all			: $(LIB)

$(LIB)		: $(OBJS)
			@ar rcs $(LIB) $(OBJS)

$(NAME)		: main.c
			@$(CC) main.c $(LIB) -o $(NAME)

clean:
			@$(RM) $(OBJS) main.o

fclean		: clean
			@$(RM) $(NAME) $(LIB)

re			: fclean all

.PHONY		: all clean fclean re
