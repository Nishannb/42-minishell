
#include <stdio.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (n-- && *src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
