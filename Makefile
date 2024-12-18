# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 08:32:50 by hrasolof          #+#    #+#              #
#    Updated: 2024/08/15 08:32:50 by hrasolof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRCDIR = .
OBJDIR = ./obj
PRINTFDIR = ./Printf

CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c

CLIENT_OBJS = $(CLIENT_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
SERVER_OBJS = $(SERVER_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(PRINTFDIR)/libftprintf.a
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) -L$(PRINTFDIR) -lftprintf

$(SERVER): $(SERVER_OBJS) $(PRINTFDIR)/libftprintf.a
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) -L$(PRINTFDIR) -lftprintf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTFDIR)/libftprintf.a:
	@$(MAKE) -C $(PRINTFDIR)

clean:
	@$(MAKE) -C $(PRINTFDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(PRINTFDIR) fclean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
