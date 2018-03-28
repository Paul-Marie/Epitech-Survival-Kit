/*
** concatenation.c for concatenation.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu Jan 19 17:15:55 2017 BETTINELLI Paul-Marie
** Last update Sat Jul 15 09:51:18 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	**concatenation(char **tab, char **res)
{
  int	i;
  int	d;
  int	c;

  i = 0;
  while (res[i] != '\0')
    {
      c = 0;
      d = my_strlen(res[i]);
      while (tab[0][c] != '\0')
	res[i][d++] = tab[0][c++];
      res[i][d] = '\0';
      i = i + 1;
    }
  res[i] = NULL;
  return (res);
}
