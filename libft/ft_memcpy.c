/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:40:38 by kevgusma          #+#    #+#             */
/*   Updated: 2015/02/18 14:52:27 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*pts1;
	const char		*pts2;

	i = 0;
	pts1 = s1;
	pts2 = s2;
	while (i < n)
	{
		pts1[i] = pts2[i];
		i++;
	}
	return (s1);
}
