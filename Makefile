# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:20:43 by psmolich          #+#    #+#              #
#    Updated: 2025/07/29 12:20:43 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: all basic bonus clean fclean re

PUSHSWAP := push_swap
CHECKER := checker

LIB := libft/libft.a

SRCS_PUSHSWAP := push_swap.c
SRCS_CHECKER := checker.c stacka_creator.c

LST := lst_utils/ft_lstnew.c \
		lst_utils/ft_lstadd_front.c \
		lst_utils/ft_lstsize.c \
		lst_utils/ft_lstlast.c \
		lst_utils/ft_lstadd_back.c \
		lst_utils/ft_lstprint.c \
		lst_utils/ft_lstissorted.c

CC := cc
CFLAGS := -Wall -Wextra -Werror

basic: $(PUSHSWAP)

bonus: $(CHECKER) 

all: $(PUSHSWAP) $(CHECKER) 

$(PUSHSWAP): $(LIB)
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(SRCS_PUSHSWAP) $(LST) $(LIB)

$(CHECKER): $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRCS_CHECKER) $(LST) $(LIB)

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	
fclean: clean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all