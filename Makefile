# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:20:43 by psmolich          #+#    #+#              #
#    Updated: 2025/07/21 15:34:38 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: all bonus clean fclean re

NAME := push_swap
CHECKER := checker
LIB := libft.a
SRCS := ft_push_swap.c 
CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

bonus: $(CHECKER) 

$(NAME): $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIB)

$(CHECKER): $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) ft_$(CHECKER).c $(LIB)

$(LIB):
	make -C libft/
	mv -u libft/$(LIB) .

clean:
	make clean -C libft/
	rm -f $(LIB)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all