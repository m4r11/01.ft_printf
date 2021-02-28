# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 16:16:23 by mvaldeta          #+#    #+#              #
#    Updated: 2021/02/24 22:10:32 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB: none
# SYN: A makefile is a file containing a set of directives used by a make build
# automation tool to generate a target/goal.
# DESC:
# (｡◕‿◕｡)
#
SRC = ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_swap.c\
			ft_itoa.c\
			ft_split.c\
			ft_substr.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_putnbr_fd.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strmapi.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\




OBJ = $(SRC:.c=.o)

BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c\

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
		$(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

so:
	$(CC) -fPIC -c $(CFLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
