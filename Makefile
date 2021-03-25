CC			= clang -Wall -Wextra -Werror
RM			= rm -rf
LIB			= libasm.a
NASM		= nasm
NFLAGS		= -f elf64
TEST_OUT	= tests
TEST_FILE	= test/main.c
INCS_DIR	= includes/

SRCS		= $(addprefix sources/, ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s\
			ft_read.s ft_strdup.s ft_list_size_bonus.s ft_list_push_front_bonus.s)

OBJS		= $(SRCS:.s=.o)

%.o			: %.s
			@$(NASM) $(NFLAGS) -I$(INCS_DIR) $< -o $@

all			: $(LIB)

$(LIB)		: $(OBJS)
			@ar rcs $(LIB) $(OBJS)

test		: $(TEST_FILE) $(LIB)
			@$(CC) $(TEST_FILE) $(LIB) -I$(INCS_DIR) -o $(TEST_OUT)

clean:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME) $(LIB) $(TEST_OUT)

re			: fclean all

.PHONY		: all clean fclean re test
