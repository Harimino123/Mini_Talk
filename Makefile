# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Directories
SRCDIR = .
OBJDIR = ./obj
PRINTFDIR = ./Printf

# Source files
CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c
PRINTF_SRCS = Printf/ft_printf.c \
              Printf/ft_putchar.c \
              Printf/ft_putstr.c \
              Printf/ft_strlen.c \
              Printf/ft_putnbr.c \
              Printf/ft_putnbr_u.c \
              Printf/ft_dec_to_hex.c \
              Printf/dec_to_hex.c \
              Printf/adr_to_str.c

# Object files
CLIENT_OBJS = $(CLIENT_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
SERVER_OBJS = $(SERVER_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
PRINTF_OBJS = $(PRINTF_SRCS:$(PRINTFDIR)/%.c=$(OBJDIR)/%.o)

# Executables
CLIENT = client
SERVER = server

# Targets
all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(PRINTF_OBJS)
	@$(MAKE) -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(PRINTF_OBJS)

$(SERVER): $(SERVER_OBJS) $(PRINTF_OBJS)
	@$(MAKE) -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(PRINTF_OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(PRINTFDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(PRINTFDIR) clean
	rm -rf $(OBJDIR) $(CLIENT) $(SERVER)

fclean: clean
	@echo "Removing $(OBJDIR), $(CLIENT), $(SERVER), and $(PRINTFDIR)/libftprintf.a"
	rm -rf $(OBJDIR) $(CLIENT) $(SERVER) $(PRINTFDIR)/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
