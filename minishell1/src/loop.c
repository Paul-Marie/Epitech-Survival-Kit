/*
** loop.c for loop.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Mar 14 10:11:27 2017 BETTINELLI Paul-Marie
** Last update Tue Apr  4 08:40:12 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

extern int	g_value;

int	loop(char **tab, char **concatenate)
{
  pid_t	pid;
  int	i;
  int	d;
  int	status;

  i = (d = (status = 0));
  while (concatenate[i] != '\0')
    if (access(concatenate[i++], X_OK) == 0 && d == 0)
      {
	if ((pid = fork()) == -1)
	  exit(84);
	if (pid == 0)
	  execve(concatenate[i - 1] , tab, environ);
	wait(&status);
	g_value = WEXITSTATUS(status);
	if (WCOREDUMP(status))
	  get_sigsegv(10);
	else
	  wait(&pid);
	d = 1;
      }
  return (d);
}

char	**exec_binary(char **tab)
{
  int	i;

  i = 0;
  if (tab[1] == NULL)
    {
      tab[0][0]= '\0';
      return (tab);
    }
  while (tab[i + 1] != '\0')
    {
      tab[i] = tab[i + 1];
      i = i + 1;
    }
  tab[i] = '\0';
  return (tab);
}

char	*remove_begin(char *str)
{
  int	i;

  i = 0;
  while (str[i + 2] != '\0')
    {
      str[i] = str[i + 2];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

int	check_binary(char **tab)
{
  char	*str;
  int	i;
  int	d;

  i = (d = 0);
  if (tab[0][0] == '.' && tab[0][1] == '/')
    {
      str = malloc(sizeof(char) * (256));
      str = getcwd(str, 256);
      i = my_strlen(str);
      str[i++] = '/';
      tab[0] = remove_begin(tab[0]);
      while (tab[0][d] != '\0')
	str[i++] = tab[0][d++];
      str[i] = '\0';
      if (access(str, X_OK) == 0)
	access_to_pid(tab, str, i);
      else
	{
	  my_putstrror(str);
	  my_putstrror(": Command not found.\n");
	}
      return (1);
    }
  return (0);
}

char	*remove_begin_abs(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = str[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}
