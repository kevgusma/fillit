/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <kevgusma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:17:06 by kevgusma          #+#    #+#             */
/*   Updated: 2013/12/05 14:09:22 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_write(char *str, int len, unsigned int n)
{
	int	i;
	int	j;

	i = 0;
	j = len;
	while (i < len)
	{
		str[j - 1] = n % 10 + 48;
		n = n / 10;
		i++;
		j--;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa_write_nega(char *str, int len, unsigned int n)
{
	int	i;
	int	j;

	i = 0;
	j = len;
	while (i < len)
	{
		str[j] = n % 10 + 48;
		n = n / 10;
		i++;
		j--;
	}
	str[0] = '-';
	str[len + 1] = '\0';
	return (str);
}

char	*ft_itoa_conv(int n)
{
	char			*str;
	int				nega;
	unsigned int	len;
	unsigned int	uns_n;

	len = 0;
	nega = 0;
	if (n < 0)
	{
		n *= -1;
		nega = 1;
	}
	uns_n = (unsigned)n;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	str = malloc(sizeof(char) * (nega + len + 1));
	if (nega == 1)
		return (ft_itoa_write_nega(str, len, uns_n));
	else
		return (ft_itoa_write(str, len, uns_n));
}

char	*ft_itoa_nb(int n)
{
	char	*str;

	if (n < 0)
	{
		str = malloc(sizeof(char) * 3);
		str[0] = '-';
		str[1] = n + 48;
		str[2] = '\0';
		return (str);
	}
	else if (n > 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = n + 48;
		str[1] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = n + 48;
		str[1] = '\0';
		return (str);
	}
	else if (n >= -9 && n <= 9)
		return (ft_itoa_nb(n));
	else if (n <= -10 || n >= 10)
		return (ft_itoa_conv(n));
	return (NULL);
}
