/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:55:18 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:55:55 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*pptr;

	pptr = ptr;
	i = 0;
	while (i < n)
	{
		pptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
