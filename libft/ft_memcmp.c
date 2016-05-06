/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:34:53 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/01 15:46:41 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	unsigned int			nb;
	unsigned const char		*pts1;
	unsigned const char		*pts2;

	i = 0;
	nb = 0;
	pts1 = (unsigned char *)s1;
	pts2 = (unsigned char *)s2;
	while (i < n)
	{
		if (pts1[i] != pts2[i])
			return (nb = (int)pts1[i] - (int)pts2[i]);
		i++;
	}
	return (nb);
}
