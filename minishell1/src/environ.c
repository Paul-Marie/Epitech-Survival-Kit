/*
** environ.c for environ.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 14 09:02:39 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 12:47:44 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

int		split_set_env(char **tab, int i, int d, int k)
{
  if (tab[1] != NULL && tab[2] != NULL && tab[3] == NULL)
    {
      if ((fill_fill(tab, i, d, k)) == 1)
	return ((g_value = 0) + 1);
      return ((fill_environ(tab, i, d, k)));
    }
  else
    return ((g_value = 1) - 1
	    + putreturn("setenv: Too many arguments.\n"));
}

int		null_fill(char **tab, int i, int d, int k)
{
  extern char	**environ;

  while (environ[i] != '\0')
    {
      if ((my_strcmp(tab[1], environ[i])) == 1)
	{
	  d = my_strlen(tab[1]) + 1;
	  environ[i][d] = '\0';
	  return (1);
	}
      i = i + 1;
    }
  environ[i] = malloc(sizeof(char) * my_strlen(tab[1]) + 2);
  while (tab[1][k] != '\0')
    environ[i][d++] = tab[1][k++];
  environ[i][d++] = '=';
  environ[i++][d] = '\0';
  environ[i] = malloc(sizeof(char));
  environ[i] = '\0';
  return (1);
}

int		fill_fill(char **tab, int i, int d, int k)
{
  extern char	**environ;

  while (environ[i] != '\0')
    {
      if ((my_strcmp(tab[1], environ[i])) == 1)
	{
	  environ[i] = malloc(sizeof(char)
			      * (my_strlen(tab[1]) + my_strlen(tab[2]) + 2));
	  while (tab[1][k] != '\0')
	    environ[i][d++] = tab[1][k++];
	  environ[i][d++] = '=';
	  k = 0;
	  while (tab[2][k] != '\0')
	    environ[i][d++] = tab[2][k++];
	  environ[i][my_strlen(environ[i])] = '\0';
	  return (1);
	}
      i = i + 1;
    }
  return ((fill_environ(tab, i, d, k)));
}

int		my_unsetenv(char **tab)
{
  extern char	**environ;
  int		i;
  int		d;

  if (tab[0][0] == 'u' && tab[0][1] == 'n' && tab[0][2] == 's' &&
      tab[0][3] == 'e' && tab[0][4] == 't' && tab[0][5] == 'e' &&
      tab[0][6] == 'n' && tab[0][7] == 'v' && tab[0][8] == '\0' &&
      tab[1] == NULL)
    return ((g_value = 1) -1 + putreturn("unsetenv: Too few arguments.\n"));
  if (tab[0][0] == 'u' && tab[0][1] == 'n' && tab[0][2] == 's' &&
      tab[0][3] == 'e' && tab[0][4] == 't' && tab[0][5] == 'e' &&
      tab[0][6] == 'n' && tab[0][7] == 'v' && tab[0][8] == '\0')
    {
      i = 1;
      while (tab[i++] != NULL)
	{
	  d = 0;
	  while (environ[d++] != '\0')
	    if (my_strcmp(tab[i - 1], environ[d - 1]) == 1)
	      environ = swap_tab(environ, d - 1);
	}
      return (1);
    }
  return (builtin_env(tab));
}

int		fill_environ(char **tab, int i, int d, int k)
{
  extern char	**environ;

  environ[i] = malloc(sizeof(char)
		      * (my_strlen(tab[1]) + my_strlen(tab[2]) + 2));
  while (tab[1][k] != '\0')
    environ[i][d++] = tab[1][k++];
  environ[i][d++] = '=';
  k = 0;
  while (tab[2][k] != '\0')
    environ[i][d++] = tab[2][k++];
  environ[i][my_strlen(environ[i])] = '\0';
  environ[++i] = malloc(sizeof(char) * 2);
  environ[i] = '\0';
  return (1);
}
