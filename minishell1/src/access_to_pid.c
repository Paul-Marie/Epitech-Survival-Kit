/*
** access_to_pid.c for access_to_pid.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 14 10:35:18 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 08:44:49 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

void	access_to_pid(char **tab, char *str, int i)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    exit(84);
  if (pid == 0)
    execve(str, tab, environ);
  wait(&i);
  g_value = WEXITSTATUS(i);
  if (WCOREDUMP(i))
    get_sigsegv(10);
  else
    wait(&pid);
}
