/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:09:00 by kevgusma          #+#    #+#             */
/*   Updated: 2013/11/25 13:30:30 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*pts;

	i = 0;
	pts = (unsigned char *)s;
	while (i < n)
	{
		if (pts[i] == (unsigned char)c)
			return (&pts[i]);
		i++;
	}
	return (NULL);
}
