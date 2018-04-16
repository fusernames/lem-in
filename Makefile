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
SRC				=	$(wildcard *.c)
OBJ				=	$(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
