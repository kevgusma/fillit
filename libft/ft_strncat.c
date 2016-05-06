/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:23:00 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/01 15:59:46 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*pts1;
	char			*pts2;

	pts1 = (char *)s1;
	pts2 = (char *)s2;
	i = 0;
	while (pts1[i] != '\0')
		i++;
	j = i;
	i = 0;
	while (i < n && pts2[i] != '\0')
	{
		pts1[i + j] = pts2[i];
		i++;
	}
	pts1[i + j] = '\0';
	return (s1);
}
