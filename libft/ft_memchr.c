
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_pointer;

	index = 0;
	s_pointer = (unsigned char *)s;
	while (index < n)
	{
		if (s_pointer[index] == (unsigned char)c)
			return (&s_pointer[index]);
		index++;
	}
	return (0);
}
