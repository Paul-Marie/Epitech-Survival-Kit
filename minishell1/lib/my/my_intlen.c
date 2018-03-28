/*
** my_intlen.c for my_intlen.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:42:58 2017 BETTINELLI Paul-Marie
** Last update Tue Jan 17 09:43:37 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	my_intlen(int nbr)
{
  int	i;

  i = 0;
  while (nbr != 0)
    {
      nbr = nbr / 10;
      i = i + 1;
    }
  return (i);
}
