/*
** cmd.c for cmd.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Fri Jan 20 11:01:21 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 08:43:39 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

char		*get_oldpwd()
{
  extern char	**environ;
  char		*str;
  int		i;
  int		d;
  int		e;

  str = malloc(sizeof(char) * (256 + 1));
  i = 0;
  d = 7;
  e = 0;
  while (environ[i] != '\0')
    {
      if (environ[i][0] == 'O' && environ[i][1] == 'L' && environ[i][2] == 'D'
	  && environ[i][3] == 'P' && environ[i][4] == 'W'&& environ[i][5] == 'D'
	  && environ[i][6] == '=' && environ[i] != '\0')
	{
	  while (environ[i][d] != '\0')
	    str[e++] = environ[i][d++];
	  str[e] = '\0';
	}
      i = i + 1;
    }
  return (str);
}

int	home()
{
  int	i;
  int	d;

  i = 0;
  d = 0;
  while (environ[i][d] != '\0')
    {
      while (environ[i][d] != '\0')
	{
	  if (environ[i][0] == 'H' && environ[i][1] == 'O'
	      && environ[i][2] == 'M' && environ[i][3] == 'E'
	      && environ[i][4] == '=')
	    return (i);
	  d = d + 1;
	}
      i = i + 1;
      d = 0;
    }
  return (0);
}

int	e_xit(char **tab)
{
  if (tab[0][0] == 'e' && tab[0][1] == 'x' && tab[0][2] == 'i'
      && tab[0][3] == 't' && tab[0][4] == '\0')
    {
      if (tab[1] == '\0')
	{
	  my_putstr("exit\n");
	  exit(0);
	}
      else if ((tab[1] != '\0' && (is_number(tab[1])) == 1) && tab[2] == '\0')
	{
	  my_putstr("exit\n");
	  exit(number(tab[1]));
	}
      else
	{
	  my_putstrror("exit: Expression Syntax.\n");
	  return (1);
	}
    }
  return (0);
}

int	chdirectory(char **tab)
{
  int	e;

  e = 0;
  if (tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0')
    {
      e = 1;
      if (tab[1] == '\0' || tab[1][0] == '~')
	chdir_home();
      else if ((tab[1][0] == '.' && tab[1][1] == '.') || tab[0][2] == '-')
	chdir("..");
      else if (tab[1][0] == '-' && tab[1][1] == '\0')
	chdir(get_oldpwd());
      else
	if (chdir(tab[1]) == -1)
	  {
	    my_putstrror(tab[1]);
	    my_putstrror(": No such file or directory.\n");
	    g_value = 1;
	  }
    }
  else
    e = check_binary(tab);
  return (e);
}

void	cmd(char **tab, int d)
{
  int	e;

  e = e_xit(tab);
  e = e + chdirectory(tab);
  e = e + set_env(tab);
  e = e + check_binary_abs(tab);
  if (e == 0)
    e = e + check_relative(tab);
  if (d + e == 0)
    not_found(tab);
}
