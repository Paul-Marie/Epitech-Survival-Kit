/*
** get_path.c for get_path.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Wed Jan 18 09:44:36 2017 BETTINELLI Paul-Marie
** Last update Sat Jul 15 09:36:01 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	*end(char *str)
{
  int	i;

  i = my_strlen(str);
  str[i] = '>';
  str[i + 1] = ' ';
  str[i + 2] = '\0';
  return (str);
}

char	*get_my_str()
{
  char	*str;

  str = malloc(sizeof(char) * (128 + 1));
  str = getcwd(str, 128);
  str = my_revstr(str);
  return (str);
}

char    *get_path()
{
  char  *prompt;
  char  *str;
  int   i;
  int   d;

  i = 0;
  d = 0;
  if ((str = get_shpath()) == NULL)
    return (NULL);
  if ((prompt = malloc(sizeof(char) * (strlen(str) + 3))) == NULL)
    return (NULL);
  while (str[d])
    prompt[i++] = str[d++];
  prompt[i++] = '>';
  prompt[i++] = ' ';
  prompt[i] = '\0';
  return (prompt);
}

char	*get_shpath()
{
  char	*path;
  char	*pdir;
  char	*cdir;

  if ((path = strdup(getenv("PWD"))) == NULL)
    return (NULL);
  cdir = path;
  if (path == NULL)
    return (NULL);
  while (*path != 0)
    {
      if (*path == '/')
	{
	  pdir = cdir;
	  cdir = path + 1;
	}
      path = path + 1;
    }
  return (pdir);
}
