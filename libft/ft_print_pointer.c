
#include "libft.h"

int	ft_print_pointer(unsigned long long p, t_flags *flags)
{
	int	count;

	count = 0;
	flags->hash = 0;
	count += ft_print_string("0x");
	count += ft_print_hexa(p, 'x', flags);
	return (count);
}
