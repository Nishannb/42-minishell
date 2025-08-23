
#include "../../shell.h"

void	free_argv(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_redir(void *ptr)
{
	t_redir	*redir;

	redir = (t_redir *)ptr;
	if (redir)
	{
		if (redir->direction)
			free(redir->direction);
		free(redir);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		ft_lstclear(&cmd->tokens, free);
		ft_lstclear(&cmd->redirs, free_redir);
		free(cmd);
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
