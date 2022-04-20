/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:45:24 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/17 23:12:37 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	lenght;

	if (s == NULL)
		return (0);
	i = -1;
	lenght = 0;
	while (s[++i])
		++lenght;
	return (lenght);
}
