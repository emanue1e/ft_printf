/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanuele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:06:09 by emanuele          #+#    #+#             */
/*   Updated: 2021/11/11 00:18:45 by emanuele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_len(char c, int *len);
void	ft_nbr(int n, int *len);
void	ft_str(char *args, int *len);
void	ft_hex(unsigned int x, int *len, char hex);
void	ft_u(unsigned int u, int *len);
void	ft_p(size_t p, int *len);

#endif
