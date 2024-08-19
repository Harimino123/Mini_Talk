/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:41:03 by hrasolof          #+#    #+#             */
/*   Updated: 2024/08/15 08:41:03 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "Printf/ft_printf.h"
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define END_TRANS '\0'

typedef struct s_list_node
{
	char				chrs;
	struct s_list_node	*next;
}						t_list_node;

void					add_char_to_list(t_list_node **head, char ch);
void					print_and_clear_list(t_list_node **head);
int						ft_atoi(const char *str);

#endif