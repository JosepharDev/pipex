/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:30:06 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 10:43:32 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_execve(char *av, t_struct pipex)
{
	pipex.cmd = ft_split(av, ' ');
	if (access(pipex.cmd[0], F_OK) == 0)
	{
		execve(pipex.cmd[0], pipex.cmd, pipex.envp);
		ft_exit();
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
