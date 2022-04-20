/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:45:08 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/20 03:48:16 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*d;
	size_t	n;

	p = (void *)malloc(count * size);
	if (p == 0)
		exit(ft_printf(">>> malloc error!\n"));
	n = count * size;
	d = (char *)p;
	while (n--)
		*d++ = 0;
	return (p);
}
