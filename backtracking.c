#include "fillit.h"

static char **make_square(size_t lenght)
{
  char **square;
  size_t  i;
  size_t  j;

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

static void display(char **square)
{
  int i;

  i = 0;
  while(square[i])
  {
    ft_putendl(square[i]);
    i++;
  }
  ft_putendl("");
}

char **remove_jeton(char **square, char id)
{
  int i;
  int j;

//display(square);
  i = 0;
  while (square[i])
  {
    j = 0;
    while(square[i][j])
    {
      if (square[i][j] == id)
      {
        square[i][j] = '.';
      }
      j++;
    }
    i++;
  }
  return (square);
}

int set_a_jeton(char **square, struct s_list *list, int i, int j)
{
  int coord;

  coord = 0;
  // segfault possible j negatif ou superieur a la map idem pour i
  while (coord < 4)
  {
    if (square[i][j] && square[i][j] == '.')
    {
      square[i][j] = list->id;
    }
    else
    {
      square = remove_jeton(square, list->id);
      return (-1);
    }
    coord++;
    if (coord == 4)
      break ;
    i += list->x[coord] - list->x[coord - 1];
    j += list->y[coord] - list->y[coord - 1];
    if (i == 4 || j == 4) // sinon segfault voir plus haut connard
    {
      square = remove_jeton(square, list->id);
      return (-1);
    }
  //  printf("i = %d et %d\n", i, j);
  }

  ft_putendl("on set a 1");
  return (0);
}
// (i*LARGEUR_TABLEAU) + j peut etre une position passer en parametre
// pour le retrouver i = position / par la largeur et j = position% largeur
//
int  brute_force(struct s_list *list, char **square, int previ, int prevj)
{
  int i;
  int j;

  if (list == NULL)
    return (1);
  i = previ;
  j = prevj;
  while (square[i])
  {
    while (square[i][j])
    {
      if (square[i][j] == '.')
      {
        if (set_a_jeton(square, list, i, j) == 0)
        {
          if (brute_force(list->next, square, i, j++) == -1)
            remove_jeton(square, list->id); // seg peu etre
        }
      }
      j++;
    }
    j = 0;
    i++;
  }
  return (-1);
}

int   fake_sqrt(int decim)
{
  int i;

  i = 0;
  while ((i * i) < decim)
    i++;
  return (i);
}

void  backtracking(struct s_list *list, size_t nb_jeton)
{
  char **square;
  int  carre;
// inverser la liste avant de commencer
  (void)*list;
  printf("nb_jeton = %zu\n", nb_jeton);
  carre = fake_sqrt(nb_jeton * 4);
  square = make_square(carre);
  while (brute_force(list, square, 0, 0) != 1)
    square = make_square(carre++);
  display(square);
}
