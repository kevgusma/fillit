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
  size_t  lenght;

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
    coord++;
    if (coord == 4)
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

int  brute_force(struct s_list *list, char **square, int previ, int prevj)
{
  int i;
  int j;

(void)previ;
(void)prevj;
  if (list == NULL)
    return (1);
  i = 0;
  //printf("i = %d et j = %d\n", i ,j);
  while (square[i])
  {
    j = 0;
    while (square[i][j])
    {
      if (square[i][j] == '.')
      {
        printf("i = %d, j = %d, id = %c\n", i, j, list->id);
        if (set_a_jeton(square, list, i, j) == 0)
        {
          ft_putendl("jeton set");
          display(square);
          sleep(1);
          if (brute_force(list->next, square, i, j + 1) == 1)
          {
            return (1);
          }
          else
            remove_jeton(square, list->id); // seg peu etre

        }
      }
      j++;
    }
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
  printf("taille du carre = %d\n", carre);
  square = make_square(carre);
  while (brute_force(list, square, 0, 0) != 1)
    square = make_square(carre++);
  display(square);
}
