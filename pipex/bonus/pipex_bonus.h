#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_list
{
	int ac;
	int proc_num;
	char **envp;
	int num_cmd;
	char **av;
	int ac;
	int **pipe;
	int infile;
	int outfile;
	pid_t pid;
}t_list;
#endif