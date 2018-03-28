/*
** my_strcpy.c for my_strcpy.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 28 08:54:39 2017 BETTINELLI Paul-Marie
** Last update Tue Mar 28 10:28:52 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	*my_strcpy(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str2[i] != '\0')
    {
      str1[i] = str2[i];
      i = i + 1;
    }
  str1[i] = '\0';
  return (str1);
}

char	*my_strcopy(char *str1, char *str2)
{
  char	*str;
  int	i;
  int	d;

  i = 0;
  d = 0;
  str = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2));
  while (str1[i] != '\0')
    str[d++] = str1[i++];
  i = 0;
  while (str2[i] != '\0')
    str[d++] = str2[i++];
  str[d] = '\0';
  return (str);
}
