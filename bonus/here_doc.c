/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:30:19 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 17:56:49 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *av, t_struct x)
{
	if (pipe(x.fd) < 0)
		ft_exit();
	x.pid = fork();
	if (x.pid == -1)
		ft_exit();
	if (x.pid == 0)
	{
		close(x.fd[0]);
		x.line = get_next_line(0);
		while (x.line)
		{
			if (ft_strncmp(x.line, av, ft_strlen(av)) == 0
				&& x.line[ft_strlen(av)] == '\n')
				exit(0);
			write(x.fd[1], x.line, ft_strlen(x.line));
			x.line = get_next_line(0);
		}
	}
	else
	{
		close(x.fd[1]);
		dup2(x.fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
