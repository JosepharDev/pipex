#include "pipex.h"

void	child_pro(char **av, char **envp, int *fd)
{
	int fd_in;
	char **path;
	char **cmd;
	char *tmp;
	char *command;

	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_in < 0)
		exit(3);
	dup2(fd[1], 1);
	dup2(fd_in, 0);
	close(fd[0]);
	tmp = get_path(envp);
	path = ft_split(tmp, ':');
	cmd = ft_split(av[2], ' ');
	command = get_cmd(path, cmd[0]);
	execve(command, cmd, envp);
}