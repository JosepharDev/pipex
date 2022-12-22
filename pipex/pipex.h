#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
void p_proc(char **envp, char **av, int *fd);
void	child_pro(char **av, char **envp, int *fd);
char *get_cmd(char **paths, char *cmd);
char *get_path(char **envp);
void p_proc(char **envp, char **av, int *fd);
char **ft_split(char *str, char c);
char *mword(char *str, char c, int *i);
int wcount(char *str, char c);
char **free_arr(char **tab);

#endif