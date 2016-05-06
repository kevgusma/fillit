/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:35:13 by kevgusma          #+#    #+#             */
/*   Updated: 2016/02/15 12:13:04 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(size_t nbr, char *base)
{
	if (nbr >= ft_strlen(base) - 1)
		ft_putnbr_base(nbr / ft_strlen(base), base);
	ft_putchar(base[nbr % ft_strlen(base)]);
}
