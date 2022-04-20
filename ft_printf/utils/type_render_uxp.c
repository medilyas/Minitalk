/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_render_uxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:45:56 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/17 20:45:58 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

void	ft_putnbr_hex(unsigned long nbr, char *base, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_hex(nbr / 16, base, count);
		*count += write(1, &base[nbr % 16], 1);
	}
	else
		*count += write(1, &base[nbr], 1);
}

int	p_render(unsigned long nbr, char *base)
{
	int	count;

	count = write(1, "0x", 2);
	ft_putnbr_hex(nbr, base, &count);
	return (count);
}

int	u_render(unsigned int nbr)
{
	char	*p;
	int		count;

	p = ft_utoa(nbr);
	count = write(1, p, ft_strlen(p));
	p = ft_free(p);
	return (count);
}

int	x_render(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	ft_putnbr_hex(nbr, base, &count);
	return (count);
}
