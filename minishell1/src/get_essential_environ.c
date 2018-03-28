/*
** get_essential_environ.c for get_essential_environ.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 28 08:45:49 2017 BETTINELLI Paul-Marie
** Last update Tue Mar 28 10:15:12 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	**get_essential_environ()
{
  char	**environ;
  int	i;

  i = 0;
  environ = malloc(sizeof(char *) * 11);
  while (i != 11)
    environ[i++] = malloc(sizeof(char) * 128);
  environ[0] = my_strcpy(environ[0], "LOGNAME=Dieu");
  environ[1] = my_strcpy(environ[1], "USER=Dieu");
  environ[2] = my_strcpy(environ[2], "GROUP=Dieu");
  environ[3] = my_strcpy(environ[3], "HOST=Dieu");
  environ[4] = my_strcopy("PWD=", getcwd(environ[4], 48));
  environ[5] = NULL;
  return (environ);
}
