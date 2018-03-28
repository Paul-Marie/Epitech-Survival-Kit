/*
** get_line.c for get_line.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu Jan 19 15:36:05 2017 BETTINELLI Paul-Marie
** Last update Fri Mar 24 10:51:16 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	get_line()
{
  extern char	**environ;
  int		i;
  int		d;

  i = 0;
  d = 0;
  while (environ[i] != '\0')
    {
      while (environ[i][d] != '\0')
	{
	  if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T'
	      && environ[i][3] == 'H' && environ[i][4] == '=')
	    return (i);
	  d = d + 1;
	}
      i = i + 1;
      d = 0;
    }
  return (0);
}
