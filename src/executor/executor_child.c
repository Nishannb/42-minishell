
#include "executor.h"

void	exec_child_process(t_cmd *cmd, t_command_group *cg, t_env *env_list,
		char **envp)
{
	init_signal(SIG_DFL, SIG_DFL);
	exec_cmd(cmd, cg, env_list, envp);
	exit(EXIT_SUCCESS);
}

void	execute_child(t_pipe_data pd)
{
	init_signal(SIG_DFL, SIG_DFL);
	setup_child_pipe(pd);
	exec_cmd(pd.cmd, pd.cg, pd.env_list, pd.envp);
	exit(EXIT_FAILURE);
}
