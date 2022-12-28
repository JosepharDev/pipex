/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:29:40 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 17:07:11 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
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

void	parent_process(t_struct pipex);
char	*get_path(t_struct pipex);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);
char	*mword(char *str, char c, int *i);
int		wcount(char *str, char c);
char	**free_arr(char **tab);
void	free_here(char **param);
void	child_process(t_struct pipex);
void	ft_exit(void);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif