/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 19:02:01 by kevgusma          #+#    #+#             */
/*   Updated: 2015/01/24 19:13:09 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] - s2[i] == 0)
		return (1);
	else
		return (0);
}
