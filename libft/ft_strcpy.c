/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:42:27 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:54:29 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;
	char	*pts1;
	char	*pts2;

	pts1 = s1;
	pts2 = (char *)s2;
	i = 0;
	while (pts2[i] != '\0')
	{
		pts1[i] = pts2[i];
		i++;
	}
	pts1[i] = '\0';
	return (s1);
}
