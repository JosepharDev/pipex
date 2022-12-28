/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:30:25 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 17:56:58 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "get_next_line.h"

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
	int		flag;
	char	*line;
}t_struct;

char	*get_path(t_struct pipex);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
char	*mword(char *str, char c, int *i);
int		wcount(char *str, char c);
char	**free_arr(char **tab);
void	free_here(char **param);
void	child_process(char *av, t_struct pipex);
void	ft_exit(void);
void	here_doc(char *av, t_struct x);
void	ft_execve(char *argv, t_struct pipex);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_open(int ac, t_struct *pipex, char **av, int flag);

#endif