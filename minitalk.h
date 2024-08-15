#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Printf/ft_printf.h"

# define END_TRANS '\0'

typedef struct s_list_node
{
    char                chrs;
    struct s_list_node  *next;
}                       t_list_node;

void add_char_to_list(t_list_node **head, char ch);
void print_and_clear_list(t_list_node **head);
int ft_atoi(const char *str);

#endif