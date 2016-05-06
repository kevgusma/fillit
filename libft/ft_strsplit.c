/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:59:27 by kevgusma          #+#    #+#             */
/*   Updated: 2015/05/02 03:48:44 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					word_number(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			count++;
		}
		else
		{
			while (s[i] != c && s[i])
				i++;
		}
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

char				**array(char const *str, char c, char **tab, int count)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	y = 0;
	while (y < count)
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		tab[y] = ft_strsub(str, j, i - j);
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		count;

	if (str == NULL)
		return (NULL);
	if (str[0] == '\0')
	{
		tab = malloc(sizeof(char));
		tab[0] = NULL;
		return (tab);
	}
	count = word_number(str, c);
	if ((tab = (char **)malloc(sizeof(char *) * count + 1)) == NULL)
		return (NULL);
	tab = array(str, c, tab, count);
	return (tab);
}
