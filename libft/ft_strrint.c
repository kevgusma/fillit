/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:54:15 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:50:54 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrint(const char *s, char c)
{
	char	*pts;
	int		i;

	if (s == NULL)
		return (-1);
	pts = (char *)s;
	i = 0;
	while (pts[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (pts[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
