/*
** my_sort_to_wordtab.c for my_sort_to_wordtab.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 12:17:51 2017 BETTINELLI Paul-Marie
** Last update Mon Mar 27 13:38:41 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	my_lines(char *str)
{
  int	i;
  int	d;

  i = 0;
  d = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ';')
	d = d + 1;
      i = i + 1;
    }
  return (d);
}

char	**my_sort_to_wordtab(char *str)
{
  char	**result;
  int	i;
  int	d;
  int	c;

  i = 0;
  c = 0;
  result = malloc(sizeof(char *) * (my_lines(str) + 1));
  while (str[c] != '\0')
    {
      d = 0;
      result[i] = malloc(sizeof(char) * (1024));
      while ((str[c] == ' ' || str[c] == '\t') && str[c] != '\0')
	c = c + 1;
      while (str[c] != '\0' && str[c] != '\t' && str[c] != ';')
	result[i][d++] = str[c++];
      c = c + 1;
      while ((str[c] == ' ' || str[c] == '\t') && str[c] != '\0')
	c = c + 1;
      i = i + 1;
    }
  result[i] = '\0';
  return (result);
}
