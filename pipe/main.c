/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:07 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/25 16:02:10 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (ac == 5)
	{
		if (pipe(pipex.fd) < 0)
			ft_exit();
		pipex.pid = fork();
		if (pipex.pid < 0)
			ft_exit();
		pipex.av = av;
		pipex.envp = envp;
		if (pipex.pid == 0)
			child_process(pipex);
		waitpid(pipex.pid, NULL, 0);
		parent_process(pipex);
	}
	else
		write(1, "Argumment Not Valid\n", 20);
	return (0);
}
