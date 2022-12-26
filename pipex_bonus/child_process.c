/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:30:00 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/26 18:28:43 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *av, t_struct pipex)
{
	if (pipe(pipex.fd) < 0)
		exit(1);
	pipex.pid = fork();
	if (pipex.pid == -1)
		exit(1);
	if (pipex.pid == 0)
	{
		close(pipex.fd[0]);
		dup2(pipex.fd[1], STDOUT_FILENO);
		ft_execve(av, pipex);
	}
	else
	{
		close(pipex.fd[1]);
		dup2(pipex.fd[0], STDIN_FILENO);
		waitpid(pipex.pid, NULL, 0);
	}
}
