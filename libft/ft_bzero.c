/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:07:47 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/18 17:25:09 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned int	i;
	unsigned char	*pstr;

	pstr = str;
	i = 0;
	while (i < n)
	{
		pstr[i] = '\0';
		i++;
	}
}
