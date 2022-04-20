/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:46:05 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/17 20:46:11 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	traitement_type(va_list args, char spec)
{
	if (spec == 'c')
		return (c_render(va_arg(args, int)));
	else if (spec == 's')
		return (s_render(va_arg(args, char *)));
	else if (spec == 'p')
		return (p_render(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (spec == 'd' || spec == 'i')
		return (di_render(va_arg(args, int)));
	else if (spec == 'u')
		return (u_render(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (x_render(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (spec == 'X')
		return (x_render(va_arg(args, unsigned long), "0123456789ABCDEF"));
	return (write(1, &spec, 1));
}

int	ft_printf(const char *input, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, input);
	count = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '%')
		{
			i++;
			count += traitement_type(args, input[i]);
		}
		else
			count += write(1, &input[i], 1);
	}
	va_end(args);
	return (count);
}
