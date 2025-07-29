# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:20:43 by psmolich          #+#    #+#              #
#    Updated: 2025/07/29 09:49:02 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT:
.PHONY: all basic bonus clean fclean re

PUSHSWAP := push_swap
CHECKER := checker

LIB := libft/libft.a

SRCS_PUSHSWAP := push_swap.c
SRCS_CHECKER := checker.c 

CC := cc
CFLAGS := -Wall -Wextra -Werror

basic: $(PUSHSWAP)

bonus: $(CHECKER) 

all: $(PUSHSWAP) $(CHECKER) 

$(PUSHSWAP): $(LIB)
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(SRCS_PUSHSWAP) $(LIB)

$(CHECKER): $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRCS_CHECKER) $(LIB)

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	
fclean: clean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all