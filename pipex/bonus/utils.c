#include "pipex_bonus.h"
#include "../pipex.h"
void here_doc(char *av, int ac)
{
	char *line;
	int fd[2];
	pid_t pid;

	if(ac < 6)
	{
		ft_error(1);
	}
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		while(get_next_line())
		{
			if(ft_strncmp(line, av, ft_strlen(av)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void dup_close(fd1, fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}
