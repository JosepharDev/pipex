/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:02:13 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/27 17:02:55 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *handle)
{
	int		i;
	char	*str;

	i = 0;
	if (!handle[i])
		return (NULL);
	while (handle[i] && handle[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (handle[i] && handle[i] != '\n')
	{
		str[i] = handle[i];
		i++;
	}
	if (handle[i] == '\n')
	{
		str[i] = handle[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_handle(char *backup)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen1(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	k = 0;
	while (backup[i])
	{
		str[k++] = backup[i++];
	}
	str[k] = '\0';
	free(backup);
	return (str);
}

char	*ft_get_line(int fd, char *handle)
{
	char	*buffer;
	int		rbyts;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	rbyts = 1;
	while (!ft_strchr(handle, '\n') && rbyts != 0)
	{
		rbyts = read(fd, buffer, BUFFER_SIZE);
		if (rbyts == -1)
		{
			free(buffer);
			return (handle);
		}
		buffer[rbyts] = '\0';
		handle = ft_strjoin1(handle, buffer);
	}
	free(buffer);
	return (handle);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*handle;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	handle = ft_get_line(fd, handle);
	if (!handle)
		return (NULL);
	buff = ft_line(handle);
	handle = ft_handle(handle);
	return (buff);
}
