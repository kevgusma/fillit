/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:25:00 by kevgusma          #+#    #+#             */
/*   Updated: 2016/05/07 16:48:06 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

static void		ft_open_file(char *name_file)
{
	int				fd;
	size_t			size;
	char			buf[MAX_CHAR + 2];
	struct s_list	*list;

	if ((fd = open(name_file, O_RDONLY)) == -1)
		ft_error("file does not exist.");
	if ((size = read(fd, buf, MAX_CHAR + 2)) <= 0 || size > MAX_CHAR)
		ft_error("file does not valid. MAX_CHAR");
	if ((size + 1) % 21 != 0)
		ft_error("file does not valid. MODULO");
	buf[size + 1] = '\n';
	buf[size + 2] = '\0';
	list = ft_check_buf(buf);
	backtracking(list, (size + 1) / 21);
}

static void		ft_usage(char *name_file)
{
	ft_putstr("usage: ");
	ft_putstr(name_file);
	ft_putendl(" source_file");
}

int				main(int ac, char **av)
{
	if (ac != 2)
		ft_usage(av[0]);
	else
		ft_open_file(av[1]);
	return (0);
}
