/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallanic <mallanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:30:23 by mallanic          #+#    #+#             */
/*   Updated: 2014/02/17 16:53:28 by mallanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strsrch(char *str, char c)
{
	int		i;

	if (str == NULL)
		return (-2);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
