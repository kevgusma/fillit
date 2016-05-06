/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:45:41 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 15:52:52 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*pts;
	int		i;

	i = 0;
	pts = (char *)s;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	str = ft_memalloc(ft_strlen(s));
	while (s[i] != '\0')
	{
		str[i] = (*f)(pts[i]);
		i++;
	}
	return (str);
}
