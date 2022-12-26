#include "pipex_bonus.h"
void	ft_execve(char *av, char **envp, t_struct pipex)
{
	
	pipex.cmd = ft_split(av, ' ');
	if (access(pipex.cmd[0], F_OK) == 0)
	{
		execve(pipex.cmd[0], pipex.cmd, pipex.envp);
		ft_exit();
	}
	pipex.tmp = get_path(pipex);
	if (!pipex.tmp)
	{
		free_here(pipex.cmd);
		ft_exit();
	}
	if (execve(pipex.tmp, pipex.cmd, pipex.envp) == -1)
		ft_exit();
}