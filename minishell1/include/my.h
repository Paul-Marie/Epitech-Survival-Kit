/*
** my.h for my.h in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1/include
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue Jan 17 09:17:16 2017 BETTINELLI Paul-Marie
** Last update Sat Jul 15 09:37:26 2017 BETTINELLI Paul-Marie
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ncurses/curses.h>
#include <curses.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

# define READ_SIZE 1

typedef struct	s_my_struct
{
  int		incr;
  int		jncr;
  int		dncr;
  int		height;
  int		width;
  int		curs_x;
  int		curs_y;
  int		ancr;
  int		bncr;
  int		posix_x;
  int		posix_y;
  int		store;
  int		argc;
  char		**argv;
}		t_struct;

extern char	**environ;

void		cmd(char **tab, int i);
void		my_exec(char **tab);
void		my_putstrror(char *str);
void		access_to_pid(char **tab, char *str, int i);
void		chdir_home();
void		my_putchar(char c);
void		my_put_nbr(int nb);
void		get_sigint(int signal);
void		get_sigsegv(int signal);
void		my_putstr(char *str);
void		not_found(char **tab);
void		my_sort_int_tab(int *tab, int size);
void		multistr(char *str1, char *str2);
int		home();
int		builtin_env(char **tab);
int		number(char *str);
int		check_relative(char **tab);
int		is_number(char *str);
int		check_binary_abs(char **tab);
int		set_env(char **tab);
int		exec_binary_abs(char *tab);
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		my_intlen(int nb);
int		normal();
int		get_line();
int		my_unsetenv(char **tab);
int		check_binary(char **tab);
int		binary_abs(char **tab);
int		check_binary_abs(char **tab);
int		loop(char **tab, char **concatenate);
int		null_fill(char **tab, int i, int d, int k);
int		fill_fill(char **tab, int i, int d, int k);
int		fill_environ(char **tab, int i, int d, int k);
int		split_set_env(char **tab, int i, int d, int k);
int		putreturn(char *str);
int		error_handling_env(char **tab);
char		*get_path();
char		*get_shpath();
char		*remove_begin_abs(char *str);
char		*my_revstr(char *str);
char		*my_strcpy(char *str1, char *str2);
char		*my_strcopy(char *str1, char *str2);
char		*get_next_line(int fd);
char		**get_cmd();
char		**get_essential_environ();
char		**my_sort_to_wordtab(char *str);
char		**my_str_to_wordtab(char *str);
char		**swap_tab(char **environ, int d);
char		**concatenation(char **tab, char **res);
t_struct	*init();

#endif /* !MY_H_ */
