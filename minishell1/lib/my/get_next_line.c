/*
** get_next_line.c for get_next_line.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Feb 21 14:33:07 2017 BETTINELLI Paul-Marie
** Last update Tue Mar  7 11:19:45 2017 BETTINELLI Paul-Marie
*/

#include "my.h"

char	*calc(char *str, char buffer[READ_SIZE + 1], int *i, int d)
{
  if ((str = malloc(sizeof(char) * (9999 + 1))) == NULL)
    return (NULL);
  if (d < READ_SIZE && d != 0)
    {
      d = d + 1;
      while (d != READ_SIZE)
	str[(*i)++] = buffer[d++];
      str[*i] = '\0';
    }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	size;
  static int	d;
  char		*str;
  int		i;

  i = 0;
  str = NULL;
  str = calc(str, buffer, &i, d);
  while ((size = read(fd, buffer, READ_SIZE)) > 0)
    {
      d = 0;
      while (buffer[d] && d < READ_SIZE)
	{
	  if (buffer[d] == '\n')
	    {
	      str[i] = '\0';
	      return (str);
	    }
	  str[i++] = buffer[d++];
	}
    }
  if ((size <= 0 || fd == -1) && i == 0)
    return (NULL);
  return (str);
}
