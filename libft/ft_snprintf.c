
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	handle_format(char specifier, va_list args, char *buffer,
		size_t buffer_size)
{
	int			len;
	const char	*s;
	char		c;

	len = 0;
	if (specifier == 'd')
		len = snprintf(buffer, buffer_size, "%d", va_arg(args, int));
	else if (specifier == 's')
	{
		s = va_arg(args, const char *);
		len = snprintf(buffer, buffer_size, "%s", s);
	}
	else if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		len = snprintf(buffer, buffer_size, "%c", c);
	}
	else
	{
		buffer[0] = specifier;
		buffer[1] = '\0';
		len = 1;
	}
	return (len);
}

void	append_buffer(char *str, size_t *j, size_t size, char *buffer)
{
	size_t	k;

	k = 0;
	while (buffer[k] && (*j) < size - 1)
	{
		str[*j] = buffer[k];
		(*j)++;
		k++;
	}
}

size_t	process_format(const char *format, va_list args,
		char *buffer, size_t **buffer_size_andi)
{
	int	len;

	len = 0;
	if (format[*buffer_size_andi[1]] == '%' && format[*buffer_size_andi[1] + 1])
	{
		(*buffer_size_andi[1])++;
		len = handle_format(format[*buffer_size_andi[1]],
				args, buffer, *buffer_size_andi[0]);
	}
	else
	{
		buffer[0] = format[*buffer_size_andi[1]];
		buffer[1] = '\0';
		len = 1;
	}
	return (len);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list args)
{
	size_t	indices[2];
	int		len;
	char	buffer[64];
	size_t	buf_size;
	size_t	*call_arr[2];

	indices[0] = 0;
	indices[1] = 0;
	buf_size = sizeof(buffer);
	len = 0;
	call_arr[0] = &buf_size;
	call_arr[1] = &indices[1];
	while (format[indices[1]])
	{
		len += process_format(format, args, buffer, call_arr);
		append_buffer(str, &indices[0], size, buffer);
		if (format[indices[1]] != '%')
			indices[1]++;
	}
	if (size > 0)
		str[indices[0]] = '\0';
	return (len);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (len);
}
