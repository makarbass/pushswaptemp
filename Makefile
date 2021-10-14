# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 15:59:05 by mclotild          #+#    #+#              #
#    Updated: 2021/10/14 19:28:06 by bpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

SRC_DIR			=	./src
INC_DIR			=	./include
OBJ_DIR			=	./.obj
LIBFT_DIR		=	./libft

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LIBS			=	-lft  -L$(LIBFT_DIR)
INCLUDES		=	-I $(INC_DIR) -I $(LIBFT_DIR)/libft

C_FILES			=	$(SRC_DIR)/push_swap.c $(SRC_DIR)/sorting.c $(SRC_DIR)/operations.c\
$(SRC_DIR)/rotate.c $(SRC_DIR)/stack.c
					
O_FILES			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

all: $(NAME)

include $(wildcard $(OBJ_DIR)*.d)

$(NAME): $(O_FILES) $(INC_DIR)/push_swap.h
	@make -sC $(LIBFT_DIR) all
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(O_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD

clean_libs:
	@make -sC $(LIBFT_DIR) clean

fclean_libs:
	@make -sC $(LIBFT_DIR) fclean

clean_obj:
	@rm -rf $(OBJ_DIR)

fclean_obj:
	@rm -rf $(OBJ_DIR) $(NAME)

clean: clean_libs clean_obj

fclean: fclean_libs fclean_obj

re:
	@$(MAKE) fclean
	@$(MAKE) all

.SECONDARY: $(O_FILES)