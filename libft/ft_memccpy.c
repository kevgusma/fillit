/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:28:14 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 16:18:09 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	char			*pts1;
	const char		*pts2;

	pts1 = s1;
	pts2 = s2;
	i = 0;
	while (i < n)
	{
		pts1[i] = pts2[i];
		if ((unsigned char)pts2[i] == (unsigned char)c)
			return (&pts1[i + 1]);
		i++;
	}
	return (NULL);
}
