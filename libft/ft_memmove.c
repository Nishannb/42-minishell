
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_pointer;
	unsigned char	*dest_pointer;

	if (src == NULL && dest == NULL)
		return (0);
	i = 0;
	src_pointer = (unsigned char *)src;
	dest_pointer = (unsigned char *)dest;
	if (dest_pointer > src_pointer)
		while (n-- != 0)
			dest_pointer[n] = src_pointer[n];
	else
	{
		while (i < n)
		{
			dest_pointer[i] = src_pointer[i];
			i++;
		}
	}
	return (dest);
}
