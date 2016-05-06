/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:48:12 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/01 15:58:38 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pts;
	char	*str;
	int		i;

	i = 0;
	pts = (char *)s;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen((char *)s));
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, pts[i]);
		i++;
	}
	return (str);
}
