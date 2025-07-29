# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 10:11:16 by psmolich          #+#    #+#              #
#    Updated: 2025/07/29 10:18:40 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

.PHONY: all clean fclean re

LIB := libft.a

FILES := memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit \
			isalnum isascii isprint toupper tolower strchr strrchr strncmp \
			strlcpy strlcat strnstr atoi calloc strdup substr strjoin strtrim \
			split itoa strmapi striteri putchar_fd putstr_fd putendl_fd \
			putnbr_fd \
			atol strcmp \
			check printf put_c_s put_uint_ptr put_int \
			get_next_line

SRCS := $(patsubst %, ft_%.c, $(FILES))
OBJS := $(patsubst %.c, %.o, $(SRCS))

CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)
	make clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)

re: fclean all
