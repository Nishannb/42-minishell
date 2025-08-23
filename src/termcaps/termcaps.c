
#include "../../shell.h"

void	exit_program(void)
{
	exit(0);
}

void	handle_input(char *buf, size_t *len, size_t buffsize)
{
	char	*str;

	g_signal_received = NOTSIG;
	str = readline("minishell: ");
	if (str == NULL)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(0);
	}
	add_history(str);
	ft_strlcpy(buf, str, buffsize);
	*len = ft_strlen(buf);
	free(str);
}
