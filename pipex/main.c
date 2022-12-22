#include "pipex.h"
void free_here(char **param)
{
	int i = 0;
	while(param[i])
	{
		free(param[i]);
		i++;
	}
	free(param);
}

char *get_path(char **envp)
{
	while(strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp+5);
}

char *get_cmd(char **paths, char *cmd)
{
	char *temp;
	char *command;

	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

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
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	tmp = get_path(envp);
	path = ft_split(tmp, ':');
	cmd = ft_split(av[2], ' ');
	command = get_cmd(path, cmd[0]);
	execve(command, cmd, envp);

}

void p_proc(char **envp, char **av, int *fd)
{
	int fd_out;
	char **path;
	char **cmd;
	char *tmp;
	char *command;

	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	tmp = get_path(envp);
	path = ft_split(tmp, ':');
	cmd = ft_split(av[3], ' ');
	command = get_cmd(path, cmd[0]);
	execve(command, cmd, envp);
}

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