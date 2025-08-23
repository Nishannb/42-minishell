
#include "executor.h"

void	handle_cmd_with_path(char *cmd_path, t_exec_ctx *ctx, char **tokens)
{
	if (access(cmd_path, X_OK) == -1)
		check_executable_access(cmd_path, ctx, tokens);
}

void	handle_cmd_without_path(char *cmd_path, t_exec_ctx *ctx, char **tokens)
{
	char	*resolved;

	resolved = find_executable_in_path(cmd_path, ctx->env_list);
	if (!resolved)
		print_error_and_exit(cmd_path, 127, ctx, tokens);
	free(resolved);
}
