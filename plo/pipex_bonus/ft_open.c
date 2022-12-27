/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:55:33 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 18:04:35 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open(int ac, t_struct *pipex, char **av, int flag)
{
	int	fd;

	fd = 0;
	if (flag == 0)
	{
		if (ac < 6)
		{
			write(1, "Argumment Not Valid\n", 20);
			exit(0);
		}
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		pipex->flag = 3;
	}
	if (flag == 1)
		fd = open(av[1], O_RDONLY, 0777);
	if (flag == 2)
	{
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		pipex->flag = 2;
	}
	if (fd == -1)
		ft_exit();
	return (fd);
}
