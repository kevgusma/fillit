/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 17:09:35 by kevgusma          #+#    #+#             */
/*   Updated: 2015/03/21 17:12:33 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strint(const char *str, char c)
{
	char			*pts;
	unsigned int	i;

	if (str == NULL || str[0] == '\0')
		return (-1);
	pts = (char *)str;
	i = 0;
	while (pts[i] != '\0')
	{
		if (pts[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
