/*
** my_revstr.c for my_revstr.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Wed Jan 18 09:39:53 2017 BETTINELLI Paul-Marie
** Last update Tue Mar 21 16:46:29 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	d;
  int	i;
  char	e;

  d = 0;
  i = 0;
  while (str[d] != '\0')
    d = d + 1;
  d = d - 1;
  while (d > i)
    {
      e = str[d];
      str[d] = str[i];
      str[i] = e;
      d = d - 1;
      i = i + 1;
    }
  return (str);
}
