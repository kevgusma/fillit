/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:11:54 by kevgusma          #+#    #+#             */
/*   Updated: 2014/03/03 13:01:42 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, unsigned int i)
{
	int	power;

	power = nb;
	if (i == 0)
		return (1);
	while (i > 1)
	{
		power = power * nb;
		i--;
	}
	return (power);
}

int	ft_nbrlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ft_add(const char *str, int op)
{
	int	i;
	int	ret;
	int	len;

	len = ft_nbrlen(str);
	ret = 0;
	i = 0;
	while (i < len)
	{
		ret = ret + op * (str[len - 1 - i] - '0') * ft_power(10, i);
		i++;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] >= 0 && str[i] <= 32)
		i++;
	if ((str[i] < '0' && str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (-1);
	if (str[i] == '-')
		return (ft_add(str + i + 1, -1));
	if (str[i] == '+')
		return (ft_add(str + i + 1, 1));
	return (ft_add(str + i, 1));
}
