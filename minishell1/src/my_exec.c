/*
** my_exec.c for my_exec.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu Jan 19 16:58:02 2017 BETTINELLI Paul-Marie
** Last update Mon Mar 27 13:16:19 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

void		get_sigint(int signal)
{
  signal = signal;
  my_putchar('\n');
  my_putstr(get_path());
}

void		get_sigsegv(int signal)
{
  signal = signal;
  my_putstrror("Segmentation fault (core dumped)\n");
}

void	my_exec(char **tab)
{
  char	**concatenate;
  char	**res;
  int	d;

  res = get_cmd();
  concatenate = concatenation(tab, res);
  d = loop(tab, concatenate);
  cmd(tab, d);
}
