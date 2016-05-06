/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:37:56 by kevgusma          #+#    #+#             */
/*   Updated: 2014/02/23 23:38:01 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_write_strtrim(const char *s, unsigned int i, unsigned int length)
{
	unsigned int	j;
	char			*str;

	str = malloc(sizeof(*str) * (length - i + 1));
	j = 0;
	while (i < length + 1)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	length;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return ("");
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	length = i;
	i = start;
	return (ft_write_strtrim(s, i, length));
}
