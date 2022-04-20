/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:31:20 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/17 23:31:44 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_asign(unsigned long *nbr, unsigned long *l_max, int *i, int *signe)
{
	*nbr = 0;
	*l_max = 9223372036854775807;
	*i = 0;
	*signe = 1;
}

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned long	nbr;
	unsigned long	l_max;

	if (!str)
		return (0);
	ft_asign(&nbr, &l_max, &i, &signe);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i++] - '0') + (nbr * 10);
		if (nbr > l_max && signe == -1)
			return (0);
		else if (nbr >= l_max && signe == 1)
			return (-1);
	}
	return (nbr * signe);
}
