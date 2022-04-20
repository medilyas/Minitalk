/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:59:07 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/21 16:28:25 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	message_or_confirmation(char *str)
{
	static int		pid;
	static int		switcher;

	if (switcher == 0)
	{
		pid = ft_atoi(str);
		switcher = 1;
	}
	else if (switcher == 1)
	{
		ft_printf("%s\n", str);
		usleep(10000);
		kill(pid, SIGUSR1);
		switcher = 0;
	}
}

char	*append_chr(char *s, char *bit)
{
	char	*byte;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	byte = ft_calloc(len + 2, sizeof(char));
	i = 0;
	while (i < len)
	{
		byte[i] = s[i];
		i++;
	}
	byte[i] = *bit;
	byte[++i] = '\0';
	return (byte);
}

void	convert(char *byte)
{
	static char	*msg;
	char		*temp;
	char		chr;
	int			pow;
	int			i;

	i = -1;
	chr = 0;
	pow = 128;
	while (byte[++i])
	{
		chr += pow * (byte[i] - '0');
		pow /= 2;
	}
	if (chr != '\0')
	{
		temp = msg;
		msg = append_chr(temp, &chr);
		free(temp);
	}
	else
	{
		message_or_confirmation(msg);
		msg = NULL;
	}
}

void	msg_handler(int sig)
{
	static char	*byte;
	static int	index;
	char		*temp;

	if (sig == SIGUSR1)
	{
		temp = byte;
		byte = append_chr(temp, "1");
		free(temp);
	}
	else if (sig == SIGUSR2)
	{
		temp = byte;
		byte = append_chr(temp, "0");
		free(temp);
	}
	if (byte == NULL)
		exit(ft_printf(">>> malloc error!\n"));
	if (++index == 8)
	{
		convert(byte);
		free(byte);
		byte = NULL;
		index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &msg_handler;
	ft_printf("Server PID: %i\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
