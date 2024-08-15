/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:07:46 by hrasolof          #+#    #+#             */
/*   Updated: 2024/08/15 00:07:46 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void add_char_to_list(t_list_node **head, char ch)
{
    t_list_node *new_node;

	new_node = malloc(sizeof(t_list_node));
    if (!new_node)
        return ; // Handle memory allocation failure
    new_node->chrs = ch;
    new_node->next = *head;
    *head = new_node;
}

// Function to print and clear the linked list
void print_and_clear_list(t_list_node **head)
{
    t_list_node *current;
    t_list_node *next_node;

	current = *head;
    while (current)
    {
        ft_printf("%c", current->chrs);
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL; // Reset the head of the list
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;
	int	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}