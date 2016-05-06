/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:09:33 by kevgusma          #+#    #+#             */
/*   Updated: 2015/02/06 18:27:41 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(int index)
{
	if (index == 1)
		ft_putendl("error: Open file fail.");
	else if (index == 2)
		ft_putendl("error: read fail.");
	else if (index == 3)
		ft_putendl("error: ant number doesn't exist.");
	else if (index == 4)
		ft_putendl("error: start doesn't exist.");
	else if (index == 5)
		ft_putendl("error: end doesn't exist.");
	else if (index == 6)
		ft_putendl("error: room doesn't exist.");
	else if (index == 7)
		ft_putendl("pas de chemin possible.");
	else if (index == 8)
		ft_putendl("file has EOF.");
	else if (index == 9)
		ft_putendl("error: same corridor.");
	exit(0);
}
