/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 08:47:24 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/21 16:02:00 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int		pid;

	if (ac < 3)
		return (ft_printf(">>> Too few arguments!\n"));
	else if (ac > 3)
		return (ft_printf(">>> Too many arguments!\n"));
	msg = to_binary(av[2]);
	if (msg == NULL)
		return (ft_printf(">>> malloc error!\n"));
	pid = ft_atoi(av[1]);
	send_message(msg, pid);
	send_message("00000000", pid);
	free(msg);
	return (0);
}
