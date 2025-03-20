/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:59:20 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/15 11:38:20 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_word(const char *str, char set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == set)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != set)
			i++;
	}
	return (count + 1);
}

size_t	lenght_word(const char *s, char set)
{
	size_t	lenght;

	lenght = 0;
	while (*s && *s != set)
	{
		s++;
		lenght++;
	}
	return (lenght);
}

void	free_memory(char **array, int elements)
{
	int	i;

	i = 0;
	while (i < elements)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	int		i;
	int		j;

	i = 0;
	str_split = malloc(sizeof(char *) * count_word(s, c));
	if (!str_split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			str_split[i] = malloc(lenght_word(s, c) + 1);
			if (!str_split[i])
				return (free_memory(str_split, i), NULL);
			while (*s && *s != c)
				str_split[i][j++] = *s++;
			str_split[i++][j] = '\0';
		}
		else
			s++;
	}
	return (str_split[i] = NULL, str_split);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	int(i), j, k;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 3));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		str[k++] = s1[i++];
	str[k] = 32;
	j = 0;
	while (s2[j])
		str[k++] = s2[j++];
	str[k] = ' ';
	str[k + 1] = '\0';
	return (str);
}
