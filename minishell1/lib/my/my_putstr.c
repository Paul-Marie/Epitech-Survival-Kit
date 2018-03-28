/*
** my_putstr.c for my_putstr.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:47:10 2017 BETTINELLI Paul-Marie
** Last update Tue Jan 17 09:47:59 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

void	my_putstr(char *str)
{
  while (*str)
    my_putchar(*str++);
}
