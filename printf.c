#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_str(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i])
	{
		ft_putchar_len(args[i], len);
		i++;
	}
}

void	ft_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_nbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
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

static	void	check(char s, va_list *args, int	*len, int *i)
{
	if (s == 's')
		ft_str(va_arg(*args, char *), len);
	else if (s == 'd')
		ft_nbr(va_arg(*args, int), len);
	else if (s == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char	*s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			check(s[++i], &ap, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)s[i], &len);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
