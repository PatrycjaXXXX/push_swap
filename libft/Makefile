# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 14:09:09 by psmolich          #+#    #+#              #
#    Updated: 2025/07/21 16:24:55 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.Phony: NAME all clean fcleam re

NAME := libft.a
FT := memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit \
			isalnum isascii isprint toupper tolower strchr strrchr strncmp \
			strlcpy strlcat strnstr atoi calloc strdup substr strjoin strtrim \
			split itoa strmapi striteri putchar_fd putstr_fd putendl_fd \
			putnbr_fd atol strcmp\
			check printf put_c_s put_uint_ptr put_int \
			get_next_line \
			lstnew lstadd_front lstsize lstlast \
			lstadd_back lstdelone lstclear lstiter lstmap
SRCS := $(patsubst %, ft_%.c, $(FT))
OBJS := $(patsubst %.c, %.o, $(SRCS))
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all 
	make clean
