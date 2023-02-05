#include "ft_printf.h"

int	ft_rec_hex(unsigned long nb, char x)
{
	if (nb == (unsigned long long)-0x7fffffffffffffffL - 1)
		return (ft_putstr("8000000000000000"));
	if (nb == 0xffffffffffffffffUL)
		return (ft_putstr("ffffffffffffffff"));
	if (nb >= 16)
		ft_rec_hex(nb / 16, x);
	if (x == 'x')
		ft_putchar("0123456789abcdef"[nb % 16]);
	else
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (ft_len_num(nb, 16, 0));
}

int	ft_uint(unsigned int nb)
{
	if (nb >= 10)
		ft_uint (nb / 10);
	ft_putchar("0123456789"[nb % 10]);
	return (ft_len_num(nb, 10, 0));
}

int	ft_printf(const char *arr, ...)
{
	int		sum;
	va_list	args;

	va_start(args, arr);
	sum = 0;
	while (*arr != '\0')
	{
		if (*arr == '%')
			sum += ft_calculate(*(++arr), args);
		else
			sum += ft_putchar(*arr);
		arr++;
	}
	va_end(args);
	return (sum);
}
