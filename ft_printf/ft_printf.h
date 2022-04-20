/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:46:14 by mkabissi          #+#    #+#             */
/*   Updated: 2022/03/20 17:34:21 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_free(char *s);
int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		c_render(char c);
int		s_render(char *str);
int		p_render(unsigned long nbr, char *base);
void	ft_putnbr_hex(unsigned long nbr, char *base, int *count);
int		di_render(int nbr);
char	*ft_itoa(int n);
int		u_render(unsigned int nbr);
char	*ft_utoa(unsigned int n);
int		x_render(unsigned int nbr, char *base);

#endif
