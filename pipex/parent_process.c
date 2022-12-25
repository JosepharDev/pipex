#include "pipex.h"

void p_proc(char **envp, char **av, int *fd)
{
	int fd_out;
	char **path;
	char **cmd;
	char *tmp;
	char *command;

	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	tmp = get_path(envp);
	path = ft_split(tmp, ':');
	cmd = ft_split(av[3], ' ');
	command = get_cmd(path, cmd[0]);
	execve(command, cmd, envp);
}