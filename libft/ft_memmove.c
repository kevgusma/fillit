/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:26:08 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/01 15:47:51 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(n);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	return (s1);
}
