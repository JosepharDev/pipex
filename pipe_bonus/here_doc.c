#include "pipex_bonus.h"

void	here_doc(char *av, int ac)
{
	pid_t pid;
	int	fd;
	char *line;
	if(ac < 6)
		exit(1);
	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		while(get_next_line(&line))
		{
			if (strncmp(line, av, ft_strlen(av)) == 0)
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

int	get_next_line(char **line)
{
	char	*buffer;
	int		readed;
	int		i;
	char	c;

	i = 0;
	readed = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	readed = read(0, &c, 1);
	while (readed && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		readed = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (readed);
}