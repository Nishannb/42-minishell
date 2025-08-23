
#include "../../shell.h"

int	shell_unset(char **args, t_env *env_list)
{
	int	i;

	i = 1;
	if (!args || !args[0])
		return (1);
	while (args[i])
	{
		unset_env_value(&env_list, args[i]);
		i++;
	}
	return (0);
}
