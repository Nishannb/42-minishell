
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*pointer_copy;

	count = 0;
	pointer_copy = (unsigned char *)s;
	if (n == 0)
		return ;
	while (count < n)
	{
		pointer_copy[count++] = (unsigned char) '\0';
	}
}
