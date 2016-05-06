/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:33:25 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:52:40 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	char			*pts2;

	i = 0;
	pts2 = (char *)s2;
	if (pts2[i] == '\0')
	{
		while (i < n)
		{
			s1[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			s1[i] = pts2[i];
			i++;
		}
	}
	if (i < n)
		s1[i] = '\0';
	return (s1);
}
