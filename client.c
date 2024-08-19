/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:08:00 by hrasolof          #+#    #+#             */
/*   Updated: 2024/08/19 10:35:11 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char chr)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = chr;
	while (i > 0)
	{
		i--;
		temp_char = chr >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int			server_pid;
	const char	*msg;
	int			i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid < 0)
		{
			ft_printf("ERROR!!!!\n");
			return (0);
		}
		msg = argv[2];
		i = 0;
		while (msg[i])
			send_signal(server_pid, msg[i++]);
		send_signal(server_pid, '\0');
	}
	else
		ft_printf("ERROR!!!!\n");
}
