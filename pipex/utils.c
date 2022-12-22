#include "pipex.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}
char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int len = 0;
	char *copy;

	len = ft_strlen(s1) + ft_strlen(s2);
	copy = malloc(sizeof(char) * (len + 1));
	while(s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while(*s2)
	{
		copy[i] = *s2;
		i++;
		s2++;
	}
	copy[i] = '\0';
	return (copy);
}
char **free_arr(char **tab)
{
	int i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
int wcount(char *str, char c)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(str[i] == c)
			i++;
		else
		{
			count++;
			while(str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}
char *mword(char *str, char c, int *i)
{
	int j = 0;
	int k = 0;
	char *word = NULL;
	while(str[(*i)] == c)
		(*i)++;
	k = *i;
	while(str[(*i)] && str[(*i)] != c)
	{
		(*i)++;
		j++;
	}
	word = malloc(j * sizeof(char) + 1);
	if(!word)
		return (NULL);
	j = 0;
	while(str[k] && str[k] != c)
	{
		word[j] = str[k];
		k++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char **ft_split(char *str, char c)
{
	char **arr;
	int i = 0;
	int j = 0;
	int count = 0;

	count = wcount(str, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if(!arr)
		return (NULL);
	while(j < count)
	{
		arr[j] = mword(str, c, &i);
		if(!arr[j])
			return(free_arr(arr));
		j++;
	}
	arr[j] = 0;
	return (arr);
}