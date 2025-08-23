
#include <stdlib.h>

char	**ft_realloc(char **ptr, size_t old_size, size_t new_size)
{
	char	**new_ptr;
	size_t	i;

	i = 0;
	new_ptr = malloc(new_size * sizeof(char *));
	if (!new_ptr)
		return (NULL);
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
