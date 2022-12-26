#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int flag = 0;
	t_struct pipex;

	if(ac > 4)
	{
		pipex.av = av;
		pipex.envp = envp;
		if(strncmp("here_doc", pipex.av[1], 8) == 0)
		{
			flag = 3;
			pipex.infile = open(pipex.av[ac - 1], O_WRONLY | O_CREAT | O_APPEND , 0777);
			if (pipex.infile < 0)
				exit(1);
			here_doc(pipex.av[2], ac);
		}
		else
		{
			flag = 2;
			pipex.infile = open(pipex.av[1], O_RDONLY, 0777);
			pipex.outfile = open(pipex.av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(pipex.infile, STDIN_FILENO);
		}
		while(flag < ac - 2)
			child_process(pipex.av[flag++], envp, pipex);
		dup2(pipex.outfile, STDOUT_FILENO);
		ft_execve(pipex.av[ac - 2], envp, pipex);
	}
	else
		write(1, "Argumment Not Valid", 19);
	return (0);
}