/*
** swap_tab.c for swap_tab.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 28 12:07:37 2017 BETTINELLI Paul-Marie
** Last update Tue Mar 28 12:15:16 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	**swap(char **environ, int i, int d)
{
  char	*tmp;

  tmp = environ[i];
  environ[i] = environ[d];
  environ[d] = tmp;
  return (environ);
}

char	**swap_tab(char **environ, int d)
{
  while (environ[d] != NULL)
    {
      environ[d] = environ[d + 1];
      d = d + 1;
    }
  environ[d - 1] = NULL;
  return (environ);
}
