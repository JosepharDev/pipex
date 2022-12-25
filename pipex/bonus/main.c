#include "pipex_bonus.h"
#include "../pipex.h"
void child_process(char *av, char **envp)
{
	pid_t pid;
	int fd[2];

	if(pipe(fd) == -1)
		error();
	pid = fork();
	if(pid == -1)
		error();
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
int main(int ac, char **av, char **envp)
{
	int flag;
	int infile;
	int outfile;

	if(ac >= 5)
	{
		if(ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			outfile = select_file(av[ac - 1], flag);
			heredoc(av[2], ac);
			flag = 3;
		}
		else
		{
			flag = 2;
			outfile = open_file(av[ac - 1], 1);
			infile = open_file(av[1], 2);
			dup_close(infile, STDIN_FILENO);
		}
		while(flag < ac - 2)
			child_process(av[flag++], envp);
		execute(av[ac - 2], envp);
	}
	ft_error(1);
}