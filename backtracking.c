#include "fillit.h"

char	**remove_jeton(char **square, char id)
{
	int	i;
	int	j;

	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			if (square[i][j] == id)
				square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}

int		set_a_jeton(char **square, struct s_list *list, int i, int j)
{
	int		coord;
	size_t	lenght;

	coord = 0;
	lenght = ft_strlen(square[0]);
	while (coord < 4)
	{
		if (square[i][j] && square[i][j] == '.')
			square[i][j] = list->id;
		else
		{
			square = remove_jeton(square, list->id);
			return (-1);
		}
		if (++coord == 4)
			break ;
		i += list->x[coord] - list->x[coord - 1];
		j += list->y[coord] - list->y[coord - 1];
		if (i >= (int)lenght || j >= (int)lenght)
		{
			square = remove_jeton(square, list->id);
			return (-1);
		}
	}
	return (0);
}

// (i*LARGEUR_TABLEAU) + j peut etre une position passer en parametre
// pour le retrouver i = position / par la largeur et j = position% largeur
//

int		brute_force(struct s_list *list, char **square)
{
	int	i;
	int	j;

	if (list == NULL)
		return (1);
	i = -1;
	while (square[++i])
	{
		j = -1;
		while (square[i][++j])
		{
			if (square[i][j] == '.')
			{
				if (set_a_jeton(square, list, i, j) == 0)
				{
					if (brute_force(list->next, square) == 1)
						return (1);
					else
						remove_jeton(square, list->id);
				}
			}
		}
	}
	return (-1);
}

void	backtracking(struct s_list *list, size_t nb_jeton)
{
	char	**square;
	int		carre;

	carre = fake_sqrt(nb_jeton * 4);
	square = make_square(carre);
	while (brute_force(list, square) != 1)
		square = make_square(carre++);
	display(square);
}
