/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:52:44 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/25 15:53:23 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

void	free_here(char **param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		free(param[i]);
		i++;
	}
	free(param);
}
