# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 11:22:55 by bpatrici          #+#    #+#              #
#    Updated: 2021/10/14 19:33:30 by bpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

OBJ_DIR		=	./.obj

HEADER_FILE =	libft.h

SRC			=	ft_strlen.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c \
				ft_isprint.c ft_isascii.c ft_isalnum.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strdup.c \
				ft_atoi.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
				ft_memcmp.c ft_memccpy.c ft_memchr.c ft_memmove.c ft_calloc.c \
				ft_strjoin.c ft_itoa.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_substr.c ft_strtrim.c ft_putendl_fd.c ft_strmapi.c ft_split.c ft_striteri.c\
				ft_isspace.c ft_abs.c ft_less.c ft_atoi_long.c ft_lstnew.c ft_lstadd_front.c\
				ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstlast.c ft_lstsize.c\
				 ft_lstdelone.c ft_lstmap.c ft_join.c ft_isint.c ft_hasdup.c
OBJ			=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJ_DIR)/%.o: %.c $(HEADER_FILE)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) -o $@ -c $< $(CFLAGS) -I.

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY:	all clean fclean re