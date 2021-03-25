CC			= clang -Wall -Wextra -Werror
RM			= rm -rf
LIB			= libasm.a
NASM		= nasm
NFLAGS		= -f elf64
TEST_OUT	= test
TEST_FILE	= main.c

SRCS		= $(addprefix sources/, ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s\
			ft_read.s ft_strdup.s ft_list_size_bonus.s)

OBJS		= $(SRCS:.s=.o)

%.o			: %.s
			@$(NASM) $(NFLAGS) $< -o $@

all			: $(LIB)

$(LIB)		: $(OBJS)
			@ar rcs $(LIB) $(OBJS)

$(NAME)		: $(TEST_FILE) $(LIB)
			@$(CC) $(TEST_FILE) $(LIB) -o $(TEST_OUT)

clean:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME) $(LIB) $(TEST_OUT)

re			: fclean all

.PHONY		: all clean fclean re
