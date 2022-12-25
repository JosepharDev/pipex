#include "pipex.h" 

int main(int ac, char **av, char **envp)
{
	int	fd[2];
	pid_t pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(2);
		if (pid == 0)
		{
			child_pro(av, envp, fd);
		}
		waitpid(pid, NULL, 0);
		p_proc(envp, av, fd);
	}
	else
	{
		write(1, "Argumment Not Valid\n", 20);
	}
	return (0);
}