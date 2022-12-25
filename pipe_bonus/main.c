#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int i = 0;
	int infile;
	int outfile;
	if(ac > 4)
	{
		if(strncmp("here_doc", av[1], 8) == 0)
		{
			infile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND , 0777);
			if (infile < 0)
				exit(1);
			here_doc(av[2], ac);
		}
		else
		{
			infile = open(av[1], O_RDONLY, 0777);
			outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(infile, 0);
		}
	}
	else
		write(1, "Argumment Not Valid", 19);
	return (0);
}