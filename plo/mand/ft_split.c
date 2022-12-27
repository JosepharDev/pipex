/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:24 by yoyahya           #+#    #+#             */
/*   Updated: 2022/12/25 17:07:43 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_arr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	wcount(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*mword(char *str, char c, int *i)
{
	int		j;
	int		k;
	char	*word;

	j = 0;
	k = 0;
	while (str[(*i)] == c)
		(*i)++;
	k = *i;
	while (str[(*i)] && str[(*i)] != c)
	{
		(*i)++;
		j++;
	}
	word = malloc(j * sizeof(char) + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (str[k] && str[k] != c)
	{
		word[j++] = str[k++];
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	count = wcount(str, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	while (j < count)
	{
		arr[j] = mword(str, c, &i);
		if (!arr[j])
			return (free_arr(arr));
		j++;
	}
	arr[j] = 0;
	return (arr);
}
