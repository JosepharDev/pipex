/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:38 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 14:37:47 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_struct pipex)
{
	pipex.outfile = open(pipex.av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.outfile < 0)
		ft_exit();
	dup2(pipex.fd[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.fd[1]);
	pipex.cmd = ft_split(pipex.av[3], ' ');
	if (access(pipex.cmd[0], F_OK | X_OK) == 0)
	{
		execve(pipex.cmd[0], pipex.cmd, pipex.envp);
	}
	pipex.tmp = get_path(pipex);
	if (!pipex.tmp)
	{
		free_here(pipex.cmd);
		perror("Error");
		exit(127);
	}
	if (execve(pipex.tmp, pipex.cmd, pipex.envp) == -1)
		ft_exit();
}
