/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanuele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:06:09 by emanuele          #+#    #+#             */
/*   Updated: 2021/11/11 00:06:09 by emanuele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p(size_t	p, int	*len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (p == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (p != 0)
	{
		str[i] = base_char[p % 16];
		p /= 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_hex(unsigned int x, int *len, char hex)
{
	char	str[25];
	char	*base_char;
	int		i;

	if (hex == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_u(unsigned int u, int *len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789";
	i = 0;
	if (u == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (u != 0)
	{
		str[i] = base_char[u % 10];
		u /= 10;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}
