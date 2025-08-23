
#include <stddef.h>

char	*ft_strchr(const char *s, int c);

char	*find_next_token(char **saveptr, const char *delim)
{
	char	*token;

	while (**saveptr && ft_strchr(delim, **saveptr))
		(*saveptr)++;
	if (**saveptr == '\0')
		return (NULL);
	token = *saveptr;
	while (**saveptr && ft_strchr(delim, **saveptr) == NULL)
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = '\0';
		(*saveptr)++;
	}
	else
		*saveptr = NULL;
	return (token);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saveptr;

	if (str)
		saveptr = str;
	if (!saveptr)
		return (NULL);
	return (find_next_token(&saveptr, delim));
}
