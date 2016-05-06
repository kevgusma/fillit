/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:05:40 by kevgusma          #+#    #+#             */
/*   Updated: 2015/02/06 18:16:47 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_str(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i - j + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	if (s2 == NULL)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	return (ft_check_str(s1, s2));
}
