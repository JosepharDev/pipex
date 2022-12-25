#include "pipex.bonus.h"

void child_process(char *av, char **envp)
{
	pid_t pid;
	int fd[2];

	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if(pid == -1)
		exit(1);
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		excute(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}