/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 19:10:59 by kevgusma          #+#    #+#             */
/*   Updated: 2016/05/07 19:36:10 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_jeton(char **buf)
{
	int		i;
	int		j;
	int		total;

	total = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (buf[i][++j])
		{
			if (j < 3 && buf[i][j] == '#' && buf[i][j + 1] == '#')
				total++;
			if (i < 3 && buf[i][j] == '#' && buf[i + 1][j] == '#')
				total++;
			if (j > 0 && buf[i][j] == '#' && buf[i][j - 1] == '#')
				total++;
			if (i > 0 && buf[i][j] == '#' && buf[i - 1][j] == '#')
				total++;
		}
	}
	if (total != 6 && total != 8)
		return (-1);
	return (0);
}

struct s_list	*set_coord(struct s_list *list, char **buf, char id)
{
	int		i;
	int		j;
	int		cmpt;

	list->id = id;
	i = 0;
	cmpt = 0;
	while (i < 4)
	{
		j = 0;
		while (buf[i][j])
		{
			if (buf[i][j] != '.')
			{
				list->x[cmpt] = i;
				list->y[cmpt] = j;
				cmpt++;
			}
			j++;
		}
		i++;
	}
	return (list);
}

struct s_list	*set_a_node(char **buf, struct s_list *list)
{
	struct s_list		*tmp;
	struct s_list		*new_node;

	if (!list)
	{
		if ((list = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
			ft_error("malloc fail.");
		list->next = NULL;
		if (check_jeton(buf) == -1)
			ft_error("Invalid jeton in file.");
		list = set_coord(list, buf, 'A');
	}
	else
	{
		if ((new_node = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
			ft_error("malloc fail.");
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		if (check_jeton(buf) == -1)
			ft_error("Invalid jeton in file.");
		new_node = set_coord(new_node, buf, tmp->id + 1);
		tmp->next = new_node;
	}
	return (list);
}

void			show_coord(struct s_list *list)
{
  int	cmpt;

  while (list)
  {
    cmpt = 0;
    printf("id de la piece %c\n", list->id);
    while (cmpt < 4)
    {
      printf("coord %d , %d\n", list->x[cmpt], list->y[cmpt]);
      cmpt++;
    }
    ft_putendl("");
    list = list->next;
  }
}

struct s_list	*ft_check_buf(char *buf)
{
	int				i;
	int				j;
	char			**split_buf;
	struct s_list	*list;

	i = -1;
	j = 1;
	while (buf[++i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			ft_error("Invalid character in file.");
		if ((j % 21) == 0 && (buf[i] != '\n' || buf[i - 1] != '\n'))
			ft_error("File does not valid.");
		j++;
	}
	split_buf = ft_strsplit(buf, '\n');
	if (split_buf[0] == NULL || ft_sizetab(split_buf) % 4)
		ft_error("Invalid file.");
	i = -1;
	list = NULL;
	while (split_buf[++i])
		if (i % 4 == 0)
			list = set_a_node(&split_buf[i], list);
	show_coord(list);
	return (list);
}
