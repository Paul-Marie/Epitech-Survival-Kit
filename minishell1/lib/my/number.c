/*
** number.c for number.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_navy
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu Feb  2 11:01:05 2017 BETTINELLI Paul-Marie
** Last update Thu Feb  2 11:01:06 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	number(char *str)
{
  int	i;
  int	c;
  int	power;
  int	integer;

  i = 0;
  power = 1;
  integer = 0;
  while (str[i] != '\0' && (str[i] > '9' || str[i] <= '0'))
      i = i + 1;
  c = i;
  while (str[c] != '\0' && str[c] <= '9' && str[c] >= '0')
      c = c + 1;
  while (c > 1 + i)
    {
      power = power * 10;
      c = c - 1;
    }
  while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
    {
      integer = integer + ((str[i] - '0') * power);
      power = power / 10;
      i = i + 1;
    }
  return (integer);
}
