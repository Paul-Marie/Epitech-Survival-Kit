/*
** new_cmd.c for new_cmd.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Feb 21 15:40:46 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 11:29:27 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

void	multistr(char *str1, char *str2)
{
  my_putstr(str1);
  my_putstr(str2);
}

void	my_putstrror(char *str)
{
  while (*str)
    write(2, &*str++, 1);
}

int	putreturn(char *str)
{
  my_putstr(str);
  return (1);
}

void	not_found(char **tab)
{
  my_putstrror(tab[0]);
  my_putstrror(": Command not found.\n");
  g_value = 1;
}

int		set_env(char **tab)
{
  extern char	**environ;
  int		i;
  int		d;
  int		k;

  i = (k = (d = 0));
  if (tab[0][0] == 's' && tab[0][1] == 'e' && tab[0][2] == 't' &&
      tab[0][3] == 'e' && tab[0][4] == 'n' && tab[0][5] == 'v' &&
      tab[0][6] == '\0')
    {
      if (error_handling_env(tab) == 1)
	return (1);
      if (tab[1] == NULL && tab[2] == NULL)
	{
	  while (environ[i] != 0)
	    multistr(environ[i++], "\n");
	  return ((g_value = 0) + 1);
	}
      if (tab[1] != NULL && tab[2] == NULL)
	return ((g_value = 0) + (null_fill(tab, i, d, k)));
      if ((split_set_env(tab, i, d, k)) == 1)
	return (1);
    }
  return (my_unsetenv(tab));
}
