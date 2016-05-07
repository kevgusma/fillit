/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:45:19 by kevgusma          #+#    #+#             */
/*   Updated: 2016/05/07 17:51:13 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display(char **square)
{
	int	i;

	i = 0;
	while (square[i])
	{
		ft_putendl(square[i]);
		i++;
	}
	ft_putendl("");
}

int		fake_sqrt(int decim)
{
	int	i;

	i = 0;
	while ((i * i) < decim)
		i++;
	return (i);
}

char	**make_square(size_t lenght)
{
	char		**square;
	size_t		i;
	size_t		j;

	if ((square = (char **)malloc(sizeof(char *) * lenght + 1)) == NULL)
		ft_error("Malloc fail.");
	square[lenght] = NULL;
	i = 0;
	while (i < lenght)
	{
		if ((square[i] = (char *)malloc(sizeof(char) * lenght + 1)) == NULL)
			ft_error("Malloc fail.");
		square[i][lenght] = '\0';
		j = 0;
		while (j < lenght)
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}
