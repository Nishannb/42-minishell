
#include "executor.h"
#include "../parser/parser.h"

char	**convert_list_to_arr(t_list *lst)
{
	int		len;
	char	**arr;
	int		i;

	len = ft_lstsize(lst);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (lst)
	{
		arr[i++] = (char *)lst->content;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}

static void	heredoc_loop(const char *delimiter, int fd, t_env *env_list, int is_quoted __attribute__((unused)))
{
	char	*line;
	char	*expanded_line;
	int		line_number;

	line = NULL;
	expanded_line = NULL;
	line_number = 1;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("minishell: warning: here-document at line%d", line_number);
			printf(" delimited by end-of-file (wanted `%s')\n", delimiter);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		
		// Always expand variables in heredoc content
		expanded_line = expand_env_token(line, env_list, NULL);
		if (expanded_line)
		{
			write(fd, expanded_line, ft_strlen(expanded_line));
			write(fd, "\n", 1);
			free(expanded_line);
		}
		else
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		
		free(line);
	}
}

int	execute_heredoc(const char *delimiter, t_env *env_list, int is_quoted)
{
	char	*filename;
	int		fd;

	filename = "/tmp/minishell_heredoc";
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
	{
		perror("open heredoc for writing");
		return (-1);
	}
	heredoc_loop(delimiter, fd, env_list, is_quoted);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open heredoc for reading");
		return (-1);
	}
	unlink(filename);
	return (fd);
}
