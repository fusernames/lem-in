# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 06:10:43 by alcaroff          #+#    #+#              #
#    Updated: 2018/10/12 20:54:40 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in
FLAGS			=	-Wall -Werror -Wextra
LIBFT			= 	libft/libft.a
LIBFT_INCLUDES	=	libft/includes
INCLUDES		= 	includes
OBJ_DIR			=	obj
SRC_DIR			= 	src
SRC				=	$(SRC_DIR)/lem_in.c \
					$(SRC_DIR)/check_exceptions.c \
					$(SRC_DIR)/choose_path.c \
					$(SRC_DIR)/comb.c \
					$(SRC_DIR)/creator.c \
					$(SRC_DIR)/else.c \
					$(SRC_DIR)/error.c \
					$(SRC_DIR)/free.c \
					$(SRC_DIR)/parser.c \
					$(SRC_DIR)/path.c \
					$(SRC_DIR)/print.c \
					$(SRC_DIR)/strjoinline.c \
					$(SRC_DIR)/travel.c
OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(LIBFT) $(NAME) $(INCLUDES)/lem_in.h
	@echo "BRAVO!!"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

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
