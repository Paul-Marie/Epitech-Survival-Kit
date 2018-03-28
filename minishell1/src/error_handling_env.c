/*
** error_handling_env.c for error_handling_env.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Apr  4 11:10:20 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 13:20:52 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

int		builtin_env(char **tab)
{
  extern char	**environ;
  int		i;

  if (tab[0][0] == 'e' && tab[0][1] == 'n'
      && tab[0][2] == 'v' && tab[0][3] == '\0')
    {
      i = 0;
      while (environ[i] != NULL)
	{
	  my_putstr(environ[i++]);
	  my_putchar('\n');
	}
      return (1);
    }
  return (0);
}

int	error_handling_env(char **tab)
{
  int	i;

  i = 0;
  if (tab[1] != NULL)
    {
      if (tab[1][0] < '0' || (tab[1][0] > '9' && tab[1][0] < 'A')
	  || (tab[1][0] > 'Z' && tab[1][0] < '_')
	  || (tab[1][0] > '_' && tab[1][0] < 'a') || tab[1][0] > 'z')
	return ((g_value = 1)  - 1 +
	       putreturn("setenv: Variable name must begin with a letter.\n"));
      while (tab[1][i] != '\0')
	{
	  if (tab[1][i] < '0' || (tab[1][i] > '9' && tab[1][i] < 'A')
	      || (tab[1][i] > 'Z' && tab[1][i] < '_')
	      || (tab[1][i] > '_' && tab[1][i] < 'a') || tab[1][i] > 'z')
	    return (putreturn("setenv: Variable name must ")
		    + putreturn("contain alphanumeric characters.\n")
		    + (g_value = 1) - 2);
	  i = i + 1;
	}
    }
  return (0);
}
