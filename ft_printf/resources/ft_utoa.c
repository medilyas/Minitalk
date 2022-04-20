/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:45:41 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/20 03:48:44 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	slenght(unsigned int n, int size)
{
	if (size == 0)
		size++;
	if (n >= 10)
	{
		size++;
		n = n / 10;
		size = slenght(n, size);
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	char	*p;
	int		size;

	size = slenght(n, 0);
	p = (char *)malloc(sizeof(char) *(size + 1));
	if (p == 0)
		exit(ft_printf(">>> malloc error!\n"));
	p[size--] = '\0';
	while (n >= 10)
	{
		p[size] = n % 10 + 48;
		n /= 10;
		size--;
	}
	p[size] = n % 10 + 48;
	return (p);
}
