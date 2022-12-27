/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:22 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/26 14:16:49 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(t_struct pipex)
{
	int	i;

	i = 0;
	while (pipex.envp[i] && ft_strncmp(pipex.envp[i], "PATH", 4) != 0)
		i++;
	if (pipex.envp[i] == NULL)
	{
		perror("Error");
		exit(127);
	}
	pipex.path = ft_split(pipex.envp[i] + 5, ':');
	i = 0;
	while (pipex.path[i])
	{
		pipex.tmp = ft_strjoin(pipex.path[i], "/");
		pipex.command = ft_strjoin(pipex.tmp, pipex.cmd[0]);
		free(pipex.tmp);
		if (access(pipex.command, F_OK | X_OK) == 0)
			return (pipex.command);
		free(pipex.command);
		i++;
	}
	free_here(pipex.path);
	return (NULL);
}
