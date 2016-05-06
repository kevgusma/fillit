#include "fillit.h"

void *check_jeton(char **buf, char id) // buf == &split_buf[i]
// buf = a split_buf mais a partir de i
{
  int   nb_hashtag;
  int   i;
  int   j;
  int   total;
  char  **jeton;

  nb_hashtag = 0;
  total = 0;
  i = 0;
  ft_putendl("on commence a verifier une piece"); //
  while (i < 4) // avant (i < 4)
  {
    j = 0;
    /*** hashtag et total voir si les deux sont bien utile *****/
    ft_putendl(buf[i]);
    while (buf[i][j]) // i = ligne et j = caractere
    {
      ft_putchar(buf[i][j]);
      if (buf[i][j] == '#')
      {
        ft_putendl("j < 3");
        if (j < 3 && buf[i][j + 1] && buf[i][j + 1] == '#')
        {

          total++;
        }
        ft_putendl("i < 3");
        if (i < 3 && buf[i + 1][j] && buf[i + 1][j] == '#')
        {

          total++;
        }
          ft_putendl("j > 0");
        if (j > 0 && buf[i][j - 1] && buf[i][j - 1] == '#')
        {

          total++;
        }
        ft_putendl("i > 0");
        if (i > 0 && buf[i - 1][j] && buf[i - 1][j] == '#')
        {

          total++;
        }
        nb_hashtag++;
      }
      j++;
    }
    if (nb_hashtag > 4)
      ft_error("Invalid # in file.");
    i++;
  }
  ft_putendl("piece verfier"); //
  if (total < 5)
    return (NULL);
/**** couper a partir d'ici ****/
  if ((jeton = (char **)malloc(sizeof(char *) * 5)) == NULL)
    return (NULL);

  i = 0;
  while (i < 4)
  {
    jeton[i] = ft_strdup(buf[i]);
    j = 0;
    while (jeton[i][j])
    {
      if (jeton[i][j] == '#')
        jeton[i][j] = id;
      j++;
    }
    i++;
  }
  jeton[i] = NULL;
  return (jeton);
  /*
    si un caractere sur la ligne : tester si les autres caracteres sont a i=
    et a j+
    si 4 caracteres sur la ligne : tester si aucun autre caractere dans le jeton
    si # tester si suivant # OU ## si oui
      option 1: + tester # en i= ou i++ et j+
      option 2 : + tester si ## en i+ et j+
    variable qui compte le nombre de #
  */
}

struct s_list *set_a_node(char **buf, struct s_list *list)
{
  struct s_list *tmp;

printf("taille du tableau = %zu\n", ft_sizetab(buf));
  if (ft_sizetab(buf) < 4)
    ft_error("Invalid jeton in file. !!");
  if (!list)
  {
    if ((list = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
      ft_error("malloc fail.");
    list->next = NULL;
    list->prev = NULL;
    list->flag = 0;
    list->id = 'A';
    if ((list->jeton = check_jeton(buf, 'A')) == NULL)
      ft_error("Invalid jeton in file.");
    return (list);
  }
  if ((tmp = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
    ft_error("malloc fail.");
  tmp->next = list;
  list->prev = tmp;
  tmp->flag = 0;
  tmp->id = list->id + 1;
  if ((tmp->jeton = check_jeton(buf, list->id + 1)) == NULL)
    ft_error("Invalid jeton in file.");
  return (tmp);
}

struct s_list *set_coord(struct s_list *list) // a refaire au moment de creer un maillon
{
  int i;
  int j;
  int cmpt;
  t_list *tmp;

  tmp = list;
  while (tmp)
  {
    i = 0;
    cmpt = 0;
    while (tmp->jeton[i])
    {
      j = 0;
      while (tmp->jeton[i][j])
      {
        if (tmp->jeton[i][j] != '.')
        {
          (*tmp).x[cmpt] = i;
          (*tmp).y[cmpt] = j;
          cmpt++;
        }
        j++;
      }
      i++;
    }
    tmp = tmp->next;
  }
  return (list);
}

void  show_list(struct s_list *list)
{
  int i;

  while (list)
  {
    i = 0;
    while(list->jeton[i])
    {
      ft_putendl(list->jeton[i]);
      i++;
    }
    ft_putendl("");
    list = list->next;
  }
}

void show_coord(struct s_list *list)
{
  int cmpt;

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

struct s_list *simple_to_circular(struct s_list *list)
{
  struct s_list *start;

  start = list;
  while (list->next)
    list = list->next;
  start->prev = list;
  list->next = start;
  return (list);
}

struct s_list *ft_check_buf(char *buf)
{
  int i; // c'est l'emplacement d'un caractere
  int j; // egale au nombre du caractere
  char **split_buf;
  struct s_list *list;

  i = 0;
  j = 1;
  while (buf[i])
  {
    if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
      ft_error("Invalid character in file.");
// faire des test supplementaire pour le modulo
    if ((j % 21) == 0 && (buf[i] != '\n' || buf[i - 1] != '\n')) // si c'est un '\n' on ne rentre pas dans cette condition
      ft_error("File does not valid.");
    j++;
    i++;
  }
  ft_putendl("check des caractere finis"); //
  split_buf = ft_strsplit(buf, '\n'); // fait un tableau de toute les lignes de buf sans '\n'
  if (split_buf[0] == NULL) // test : faire un if qui contient split et la verif
    ft_error("Invalid file.");
  i = 0;
  list = NULL;
  while (split_buf[i])
  {
    ft_putendl("split_buf");
    if (i % 4 == 0) // modulo de ZERO = ZERO !!!!!!!!!!!!!!
      list = set_a_node(&split_buf[i], list);
    i++;
  }
  ft_putendl("list finis"); //
  list = set_coord(list);
  show_list(list);
  show_coord(list);
//  list = simple_to_circular(list);
  ft_putendl("ON PASSE AU BACKTRAKING");
  return (list);
}
