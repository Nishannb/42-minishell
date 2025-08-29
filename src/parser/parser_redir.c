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

static void	parse_delimiter(t_redir *redir, const char *input, int *curr_pos)
{
	int		start;
	char	quote;

	start = *curr_pos;
	redir->is_quoted = 0;
	
	// Check if delimiter starts with a quote
	if (input[*curr_pos] == '\'' || input[*curr_pos] == '"')
	{
		quote = input[*curr_pos];
		redir->is_quoted = 1;
		(*curr_pos)++;  // Skip the opening quote
		start = *curr_pos;
	}
	
	// Find the end of the delimiter
	while (input[*curr_pos] && !isspace(input[*curr_pos])
		&& input[*curr_pos] != '|')
	{
		if (redir->is_quoted && input[*curr_pos] == quote)
			break;
		(*curr_pos)++;
	}
	
	// Extract the delimiter (without quotes)
	redir->direction = ft_strndup(&input[start], *curr_pos - start);
	
	// Skip the closing quote if it exists
	if (redir->is_quoted && input[*curr_pos] == quote)
		(*curr_pos)++;
}

t_redir	*get_redir(const char *input, int *curr_pos)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	
	// Initialize the structure
	redir->type[0] = '\0';
	redir->type[1] = '\0';
	redir->direction = NULL;
	redir->is_quoted = 0;
	
	set_redir_type(redir, input, curr_pos);
	ft_skip_spaces(input, curr_pos);
	parse_delimiter(redir, input, curr_pos);
	
	return (redir);
}
