/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:59:05 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/25 15:59:28 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	copy = malloc(sizeof(char) * (len + 1));
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		copy[i] = *s2;
		i++;
		s2++;
	}
	copy[i] = '\0';
	return (copy);
}
