#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_struct
{
	int		infile;
	int		outfile;
	pid_t	pid;
	int		fd[2];
	char	**path;
	char	**cmd;
	char	*tmp;
	char	*command;
	char	**envp;
	char	**av;
}t_struct;

char	*get_path(t_struct pipex);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
char	*mword(char *str, char c, int *i);
int		wcount(char *str, char c);
char	**free_arr(char **tab);
void	free_here(char **param);
void	child_process(char *av, char **envp,t_struct pipex);
void	ft_exit(void);
void	here_doc(char *av, int ac);
int get_next_line(char **line);
void	ft_execve(char *argv, char **envp,t_struct pipex);

#endif