/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:51:28 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/26 18:22:15 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_struct pipex)
{
	pipex.infile = open(pipex.av[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_exit();
	dup2(pipex.fd[1], 1);
	dup2(pipex.infile, 0);
	close(pipex.fd[0]);
	pipex.cmd = ft_split(pipex.av[2], ' ');
	if (access(pipex.cmd[0], F_OK) == 0)
	{
		execve(pipex.cmd[0], pipex.cmd, pipex.envp);
		ft_exit();
	}
	pipex.tmp = get_path(pipex);
	if (!pipex.tmp)
	{
		free_here(pipex.cmd);
		ft_exit();
	}
	if (execve(pipex.tmp, pipex.cmd, pipex.envp) == -1)
		ft_exit();
}
