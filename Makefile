# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 06:10:43 by alcaroff          #+#    #+#              #
#    Updated: 2018/02/14 06:55:44 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in
FLAGS			=	-Wall -Werror -Wextra
LIBFT			= 	libft/libft.a
LIBFT_INCLUDES	=	libft/includes
INCLUDES		= 	includes
OBJ_DIR			=	obj
SRC_DIR			= 	src
SRC				=	$(wildcard $(SRC_DIR)/*.c)
OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME) $(INCLUDES)/lem_in.h
	@echo "BRAVO!!"

$(LIBFT):
	@echo "creation de la libft.."
	@$(MAKE) -C libft

$(NAME): $(OBJ)
	@echo "creation des fichiers objets..."
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	rm -rf $(OBJ)
	@$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) fclean -C libft

re: fclean all
