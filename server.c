/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:07:36 by hrasolof          #+#    #+#             */
/*   Updated: 2024/08/15 00:07:36 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	cur_char;
	static int				bit_i;
	static t_list_node		*char_list = NULL;

	cur_char |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (cur_char == END_TRANS)
		{
			ft_printf("\n");
			print_and_clear_list(&char_list);
		}
		else
			add_char_to_list(&char_list, cur_char);
		bit_i = 0;
		cur_char = 0;
	}
	else
		cur_char <<= 1;
}

int	main(void)
{
	ft_printf("Server running...\n");
	ft_printf("ServerPID : %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
	}
	return (0);
}