/*
** my_strlen.c for my_strlen.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 10:25:19 2017 BETTINELLI Paul-Marie
** Last update Tue Jan 17 10:26:34 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
