/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:14:54 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/22 16:15:32 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*a1;
	unsigned char	*a2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while (a1[i] == a2[i] && a1[i] && a2[i])
	{
		i++;
	}
	return (a1[i] - a2[i]);
}
