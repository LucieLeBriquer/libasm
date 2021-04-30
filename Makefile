CC			= clang -Wall -Wextra -Werror
RM			= rm -rf
LIB			= libasm.a
NASM		= nasm
NFLAGS		= -f elf64
TEST_OUT	= run
TEST_FILE	= test/main.c
INCS_DIR	= includes/

SRCS		= $(addprefix sources/,\
			ft_strlen.s\
			ft_strcmp.s\
			ft_strcpy.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s)

BONUS		= $(addprefix sources/,\
			ft_list_size_bonus.s\
			ft_list_push_front_bonus.s\
			ft_list_sort_bonus.s\
			ft_list_remove_if_bonus.s\
			ft_atoi_base_bonus.s)

TEST		= $(addprefix test/,\
			test_lst.c\
			test_read.c\
			test_strcmp.c\
			test_strcpy.c\
			test_strdup.c\
			test_strlen.c\
			test_write.c)

OBJS		= $(SRCS:.s=.o)
BONUS_OBJS	= $(BONUS:.s=.o)
TEST_OBJS	= $(TEST:.c=.o)

%.o			: %.s
			@$(NASM) $(NFLAGS) -I$(INCS_DIR) $< -o $@

%.o			: %.c
			@$(CC) -I$(INCS_DIR) -c $< -o $@

all			: $(LIB)

$(LIB)		: $(OBJS) $(BONUS_OBJS)
			@ar rcs $(LIB) $(OBJS) $(BONUS_OBJS)

test		: $(TEST_FILE) $(LIB) $(TEST_OBJS)
			@$(CC) $(TEST_FILE) $(TEST_OBJS) $(LIB) -I$(INCS_DIR) -o $(TEST_OUT)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean		: clean
			@$(RM) $(NAME) $(LIB) $(TEST_OUT)

re			: fclean all

.PHONY		: all clean fclean re test
