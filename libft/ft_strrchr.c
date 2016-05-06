/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:15:51 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:51:40 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pts;
	int		i;

	if (s == NULL)
		return (NULL);
	pts = (char *)s;
	i = 0;
	while (pts[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (pts[i] == (char)c)
			return (&pts[i]);
		i--;
	}
	return (NULL);
}
