# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 11:01:28 by dpaluszk          #+#    #+#              #
#    Updated: 2024/05/14 14:47:57 by dpaluszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER=server
CLIENT=client

SERVER_BONUS=server_bonus
CLIENT_BONUS=client_bonus

all: $(SERVER) $(CLIENT)

SRC = client.c \
		server.c

BONUS = client_bonus.c \
		server_bonus.c

OBJECTS = $(SRC:.c=.o)

BONUS_OBJECTS = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

$(SERVER): server.o
	$(CC) $(FLAGS) -o $@ $^

$(CLIENT): client.o
	$(CC) $(FLAGS) -o $@ $^

$(SERVER_BONUS): server_bonus.o
	$(CC) $(FLAGS) $< -o $@

$(CLIENT_BONUS): client_bonus.o
	$(CC) $(FLAGS) $< -o $@

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) ${BONUS_OBJECTS}

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: all clean fclean re bonus