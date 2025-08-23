
#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	count++;
	return (count);
}
