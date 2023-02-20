# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 14:44:52 by aalami            #+#    #+#              #
#    Updated: 2023/01/08 15:05:55 by aalami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c \
	ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c \
	ft_atoi.c ft_memmove.c ft_strtrim.c ft_itoa.c ft_split.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_memcmp.c ft_strlcat.c ft_striteri.c \
	convert_hex.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
	ft_strchr_p.c

BONUS = ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c 

OBJ = $(SOURCES:.c=.o)

BOBJ = $(BONUS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME)  $?

bonus: $(OBJ) $(BOBJ)  
	ar -rc $(NAME) $?

%.o: %.c libft.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re