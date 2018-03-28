/*
** my_put_nbr.c for my_put_nbr.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:46:03 2017 BETTINELLI Paul-Marie
** Last update Tue Jan 17 09:46:31 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

int	power(int nb)
{
  int	i;

  i = 1;
  if (nb == 0)
    return (-1);
  while (i <= nb)
    i = i * 10;
  return (i / 10);
}

void	my_put_nbr(int nb)
{
  int	e;
  int	d;

  d = nb;
  if (nb < 0)
    {
      d = - d;
      my_putchar('-');
    }
  e = power(d);
  while (e != 0)
    {
      if (nb < 0)
	d = - (nb / e);
      else
	d = nb / e;
      my_putchar('0' + d);
      if (nb > 0)
	nb = nb - (d * e);
      else
	nb = nb + (d * e);
      e = e / 10;
    }
}
