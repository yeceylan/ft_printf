#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *arr)
{
	int	sum;

	if (!arr)
		return (write(1, "(null)", 6));
	sum = -1;
	while (arr[++sum])
		ft_putchar(arr[sum]);
	return (sum);
}

int	ft_len_num(long nb, int base, int len)
{
	if (nb == 0)
		return (1);
	while (nb > 0 && ++len)
		nb /= base;
	return (len);
}

int	ft_d(int nb, int sum)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (ft_putstr("-2147483648"));
		nb = -nb;
		ft_putchar('-');
		sum = 1;
	}
	if (nb >= 10)
		ft_d(nb / 10, sum);
	ft_putchar("0123456789"[nb % 10]);
	return (sum + ft_len_num(nb, 10, 0));
}

int	ft_calculate(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_d(va_arg(args, int), 0));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_putstr("0x") + \
			ft_rec_hex(va_arg(args, unsigned long), 'x'));
	else if (c == 'X' || c == 'x')
		return (ft_rec_hex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		return (ft_uint(va_arg(args, unsigned int)));
	return (1);
}
