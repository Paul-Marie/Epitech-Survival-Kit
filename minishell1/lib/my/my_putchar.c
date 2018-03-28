/*
** my_putchar.c for my_putchar.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/lib/my
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:45:36 2017 BETTINELLI Paul-Marie
** Last update Tue Jan 17 09:45:42 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
