NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = 	stack.c \
		args_checker.c \
		push_swap.c \
		stack_a_op.c \
		stack_b_op.c \
		push_swap_utils.c \
		push_swap_utils_2.c \
		lis_sort.c \
		sort_utils.c \
		sort_utils_2.c \
		sort_utils_3.c \
		stack_utils.c \
		stack_utils_2.c 
SRC_BNS = ./bonus/args_checker_bonus.c \
			./bonus/checker_bonus.c \
			./bonus/stack_a_op_bonus.c \
			./bonus/stack_b_op_bonus.c \
			./bonus/stack_utils_2_bonus.c \
			./bonus/stack_utils_bonus.c \
			./bonus/stack_bonus.c

OBJ = $(SRC:%.c=%.o)
OBJ_BNS = $(SRC_BNS:%.c=%.o)
LIB_DIR = lib/Libft
LIBFT = libft.a

all : $(NAME)
bonus : $(NAME) $(BONUS)

$(BONUS) : $(OBJ_BNS) ./bonus/push_swap_bonus.h
	$(CC) $(OBJ_BNS) $(CFLAGS) -L$(LIB_DIR) -lft -o $(BONUS)
$(NAME) : $(OBJ) push_swap.h
	@make bonus -C $(LIB_DIR)
	$(CC) $(OBJ) $(CFLAGS) -L$(LIB_DIR) -lft -o $(NAME)

%_bonus.o: %_bonus.c
	$(CC) -c $(CFLAGS) $?
	mv *_bonus.o bonus
%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean :
	@make clean -C $(LIB_DIR)
	rm -f $(OBJ)
	rm -f $(OBJ_BNS)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	@make fclean -C $(LIB_DIR)

re : fclean all
