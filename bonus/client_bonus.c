/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:58:55 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/21 16:19:16 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_confirmation(int sig)
{
	ft_printf("\n>>> ");
	if (sig == SIGUSR1)
		ft_printf("sent successfully!");
	else
		ft_printf("sent failed!");
	ft_printf(" <<<\n\n");
}

int	confirm_receipt(void)
{
	struct sigaction	sa;

	sa.sa_handler = &print_confirmation;
	sigaction(SIGUSR1, &sa, NULL);
	pause();
	return (0);
}

void	send_message(char *s, int pid)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
		i++;
	}
}

char	*to_binary(char *s)
{
	char	*binary;
	int		len;
	int		i;
	int		chr;
	int		k;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	binary = ft_calloc(len * 8 + 1, sizeof(unsigned char));
	i = -1;
	while (++i < len)
	{
		chr = (unsigned char)s[i];
		k = 8;
		while (--k >= 0)
		{
			if (chr % 2)
				binary[i * 8 + k] = '1';
			else
				binary[i * 8 + k] = '0';
			chr /= 2;
		}
	}
	return (binary);
}

int	main(int ac, char **av)
{
	char	*msg;
	char	*pid_client;
	char	*temp;
	int		pid_server;
	int		client_pid;

	if (ac < 3)
		return (ft_printf(">>> Too few arguments!\n"));
	else if (ac > 3)
		return (ft_printf(">>> Too many arguments!\n"));
	pid_server = ft_atoi(av[1]);
	client_pid = getpid();
	temp = ft_itoa(client_pid);
	pid_client = to_binary(temp);
	free(temp);
	send_message(pid_client, pid_server);
	send_message("00000000", pid_server);
	msg = to_binary(av[2]);
	send_message(msg, pid_server);
	send_message("00000000", pid_server);
	free(msg);
	confirm_receipt();
	return (0);
}
