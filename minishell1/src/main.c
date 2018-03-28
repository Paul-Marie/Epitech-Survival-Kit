/*
** main.c for main.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:53:13 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 08:40:26 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	g_value = 0;

void	isatty_not_0(char *str)
{
  char	**tab;
  char	**tables;
  int	i;

  my_putstr(get_path());
  while ((str = get_next_line(0)))
    {
      i = 0;
      tables = my_sort_to_wordtab(str);
      while (tables[i] != '\0')
	{
	  tab = my_str_to_wordtab(tables[i]);
	  ((tab[0] == '\0' || tab == NULL) ? tab[0] = tab[0] : my_exec(tab));
	  i = i + 1;
	}
      my_putstr(get_path());
      str = malloc(sizeof(char) * (512 + 1));
    }
  if (str == NULL)
    my_putstr("exit\n");
}

int		main()
{
  extern char	**environ;
  char		**tables;
  char		**tab;
  char		*str;
  int		i;

  str = malloc(sizeof(char) * (512 + 1));
  signal(SIGINT, get_sigint);
  if (environ[0] == NULL)
    environ = get_essential_environ();
  if (isatty(0) == 0)
    while ((str = get_next_line(0)))
      {
	i = 0;
	tables = my_sort_to_wordtab(str);
	while (tables[i] != '\0')
	  {
	    if ((tab = my_str_to_wordtab(tables[i]))[0] != NULL)
	      my_exec(tab);
	    i = i + 1;
	  }
      }
  else
    isatty_not_0(str);
  return (g_value);
}
