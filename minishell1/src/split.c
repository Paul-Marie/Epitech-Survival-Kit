/*
** split.c for split.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 14 15:34:17 2017 BETTINELLI Paul-Marie
** Last update Sat Jul 15 09:54:26 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

int	check_relative(char **tab)
{
  char	*str;
  int	i;
  int	d;
  int	e;

  i = (d = (e = 0));
  str = malloc(sizeof(char) * 128);
  str = getcwd(str, 128);
  i = my_strlen(str);
  str[i++] = '/';
  while (tab[0][d] != '\0')
    str[i++] = tab[0][d++];
  if (access(str, X_OK) == 0)
    {
      access_to_pid(tab, str, e);
      return (1);
    }
  return (0);
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > '9' || str[i] < '0')
	return (0);
      i = i + 1;
    }
  return (1);
}

void	chdir_home()
{
  char	*str;
  int	i;
  int	d;

  i = 5;
  d = 0;
  str = malloc(sizeof(char) * (256));
  while (environ[home()][i] != '\0')
    str[d++] = environ[home()][i++];
  str[d] = '\0';
  chdir(str);
}

int	check_binary_abs(char **tab)
{
  char	*str;
  int	e;

  e = 0;
  if (tab[0][0] == '/' && tab[0][1] != '\0')
    {
      str = malloc(sizeof(char) * (256));
      str = remove_begin_abs(tab[0]);
      if (access(str, X_OK) == 0)
	access_to_pid(tab, str, e);
      else
	{
	  multistr(str, ": Command not found.\n");
	  g_value = 1;
	}
      return (1);
    }
  return (0);
}
