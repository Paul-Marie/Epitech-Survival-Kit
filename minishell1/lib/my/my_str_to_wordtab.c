/*
** my_sort_to_wordtab.c for my_sort_to_wordtab.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 12:17:51 2017 BETTINELLI Paul-Marie
** Last update Sat Jul 15 09:48:27 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	my_line(char *str)
{
  int	i;
  int	d;

  i = 0;
  d = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	d = d + 1;
      i = i + 1;
    }
  return (d);
}

char	**my_str_to_wordtab(char *str)
{
  char	**result;
  int	i;
  int	d;
  int	c;

  i = 0;
  c = 0;
  result = malloc(sizeof(char *) * (my_line(str) + 2));
  while (str[c] != '\0')
    {
      d = 0;
      result[i] = malloc(sizeof(char) * (1024 + 1));
      while ((str[c] == ' ' || str[c] == '\t') && str[c] != '\0')
	c = c + 1;
      while (str[c] != '\0' && str[c] != ' ' && str[c] != '\t')
	result[i][d++] = str[c++];
      result[i][d] = '\0';
      while ((str[c] == ' ' || str[c] == '\t') && str[c] != '\0')
	c = c + 1;
      i = i + 1;
    }
  result[i] = malloc(sizeof(char) * 1);
  result[i] = NULL;
  return (result);
}
