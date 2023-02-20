NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = 	stack.c \
		args_checker.c \
		push_swap.c \
		stack_a_op.c \
		stack_b_op.c \
		push_swap_utils.c
OBJ = $(SRC:.c=.o)
LIB_DIR = lib/Libft
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJ) push_swap.h
	@make bonus -C $(LIB_DIR)
	$(CC) $(OBJ) $(CFLAGS) -L$(LIB_DIR) -lft -o $(NAME)
%.o: %.c 
	$(CC) -c $(CFLAGS) $?

clean :
	@make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re : fclean all
