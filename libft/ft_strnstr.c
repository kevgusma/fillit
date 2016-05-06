/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:08:21 by kevgusma          #+#    #+#             */
/*   Updated: 2015/02/06 18:19:07 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_check(char *s1, char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	index;
	unsigned int	id;

	id = 0;
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		i = id;
		j = 0;
		if (s1[i] == s2[j])
		{
			index = i;
			while (s1[i] == s2[j] && i < n && s1[i] != '\0')
			{
				i++;
				j++;
			}
			if (j == strlen(s2))
				return ((char *)&s1[index]);
		}
		id++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	if (ft_str_check((char *)s1, (char *)s2, n) != NULL)
		return (ft_str_check((char *)s1, (char *)s2, n));
	return (NULL);
}
