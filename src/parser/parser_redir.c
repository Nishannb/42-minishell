
#include "parser.h"

static void	set_redir_type(t_redir *redir, const char *input, int *curr_pos)
{
	if (ft_strncmp(&input[*curr_pos], ">>", 2) == 0)
	{
		strcpy(redir->type, ">>");
		*curr_pos += 2;
	}
	else if (ft_strncmp(&input[*curr_pos], "<<", 2) == 0)
	{
		strcpy(redir->type, "<<");
		*curr_pos += 2;
	}
	else
	{
		redir->type[0] = input[(*curr_pos)++];
		redir->type[1] = '\0';
	}
}

t_redir	*get_redir(const char *input, int *curr_pos)
{
	t_redir	*redir;
	int		start;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	set_redir_type(redir, input, curr_pos);
	ft_skip_spaces(input, curr_pos);
	start = *curr_pos;
	while (input[*curr_pos] && !isspace(input[*curr_pos])
		&& input[*curr_pos] != '|')
		(*curr_pos)++;
	redir->direction = ft_strndup(&input[start], *curr_pos - start);
	return (redir);
}
