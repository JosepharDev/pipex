#include "pipex.h"

char *get_path(char **envp)
{
	while(strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
		return (NULL);
	return (*envp+5);
}