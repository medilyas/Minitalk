/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_render_csdi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:45:49 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/17 20:45:51 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	c_render(char c)
{
	return (write(1, &c, 1));
}

int	s_render(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	di_render(int nbr)
{
	char	*p;
	int		count;

	p = ft_itoa(nbr);
	count = write(1, p, ft_strlen(p));
	p = ft_free(p);
	return (count);
}
