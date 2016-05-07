/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:25:18 by kevgusma          #+#    #+#             */
/*   Updated: 2016/05/07 20:02:53 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define MAX_CHAR 545

typedef struct		s_list
{
	char			id;
	int				x[4];
	int				y[4];
	struct s_list	*next;
}					t_list;

int					fake_sqrt(int decim);
void				display(char **square);
void				ft_error(char *str);
void				backtracking(struct s_list *list, size_t nb_jeton);
char				**make_square(size_t lenght);
struct s_list		*ft_check_buf(char *buf);

#endif
