/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:38:44 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/01 15:57:08 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlconc(char *s1, char *s2, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;

	n = size - 1;
	i = 0;
	j = 0;
	while (n > 0 && s1[i] != '\0')
	{
		n--;
		i++;
	}
	while (n > 0 && s2[j] != '\0')
	{
		s1[i] = s2[j];
		n--;
		i++;
		j++;
	}
	s1[i] = '\0';
}

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	unsigned int	len;

	len = ft_strlen(s1);
	if (size == 0)
		return (ft_strlen(s2));
	else if (size <= len)
		return (ft_strlen(s2) + size);
	else
		ft_strlconc(s1, (char *)s2, size);
	return (len + ft_strlen(s2));
}
