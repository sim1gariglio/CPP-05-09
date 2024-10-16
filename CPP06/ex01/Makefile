# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:08:55 by sgarigli          #+#    #+#              #
#    Updated: 2024/10/15 12:08:56 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

SRCS = Serializer.cpp \
	main.cpp \

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

CC = c++

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
