# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:09:45 by sekeskin          #+#    #+#              #
#    Updated: 2024/11/20 17:32:05 by sekeskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_memset.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_memcpy.c		\
		ft_strchr.c		\
		ft_strlen.c

OBJ = $(SRC:.c=.o)

GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\n	$(GREEN) $@ built $(RESET)\n"

clean:
	@/bin/rm -f  $(OBJ)
	@echo "\n	$(YELLOW) object files removed $(RESET)\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "	$(YELLOW) static library removed $(RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re