/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:30:22 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/26 19:04:12 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (ac > 4)
	{
		pipex.av = av;
		pipex.envp = envp;
		if (ft_strncmp("here_doc", pipex.av[1], 8) == 0)
		{
			pipex.outfile = ft_open(ac, &pipex, av, 0);
			here_doc(pipex.av[2], ac);
		}
		else
		{
			pipex.infile = ft_open(ac, &pipex, av, 1);
			pipex.outfile = ft_open(ac, &pipex, av, 2);
			dup2(pipex.infile, STDIN_FILENO);
		}
		while (pipex.flag < ac - 2)
			child_process(pipex.av[pipex.flag++], pipex);
		dup2(pipex.outfile, STDOUT_FILENO);
		ft_execve(pipex.av[ac - 2], pipex);
	}
	else
		write(1, "Argumment Not Valid", 19);
	return (0);
}
