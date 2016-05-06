/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:59:58 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/08 15:51:44 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*pts;
	unsigned int	i;

	i = 0;
	pts = (char *)s;
	while (i < ft_strlen(pts) + 1)
	{
		if (pts[i] == (char)c)
			return (&pts[i]);
		else
			i++;
	}
	return (NULL);
}
