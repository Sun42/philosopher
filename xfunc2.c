/*
** xfunc2.c for  in /u/all/sundas_c/cu/rendu/c/philo1
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sun Mar 29 15:51:14 2009 christophe sundas
** Last update Sun Mar 29 15:51:15 2009 christophe sundas
*/
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

int	usleep(useconds_t useconds);

void	xpthread_mutex_unlock(pthread_mutex_t *mutex)
{
  int	r;

  r = pthread_mutex_unlock(mutex);
  if (r != 0)
    {
      perror("error mutex unlock");
      exit(EXIT_FAILURE);
    }
}

void	xpthread_mutex_lock(pthread_mutex_t *mutex)
{
  int	r;

  r = pthread_mutex_lock(mutex);
  if (r != 0)
    {
      perror("error mutex lock");
      exit(EXIT_FAILURE);
    }
}

void	xusleep(useconds_t useconds)
{
  int	r;

  r = usleep(useconds);
  if (r == -1)
    {
      perror("error usleep");
      exit(EXIT_FAILURE);
    }
}

void	xfree(t_astek **astek, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      free(astek[i]);
      i++;
    }
}

void	xjoin(pthread_t threads[NB_ASTEK], int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      xpthread_join(threads[i]);
      i++;
    }
}
